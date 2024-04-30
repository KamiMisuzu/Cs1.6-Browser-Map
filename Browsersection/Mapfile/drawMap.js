ConfigPath = window.location.href.split('/').filter(function(item,index){
  if(item!='index.html'){
    return true;
  }
  return false;
})
ConfigPath.push("config.json")
fetch(ConfigPath.join('/')).then(response => {
    if (!response.ok) {
      throw new Error('配置文件不存在');
    }
    return response.json();
  })
  .then(data => {
    window.Color = {"0": data["G_attribute"]["Color"]["enemy"],
    "1": data["G_attribute"]["Color"]["self"],
    "2": data["G_attribute"]["Color"]["teammate"]
    };
    window.WebSocket_IP = data["ConfigVariables"]["WebSocket"]["WebSocket_IP"];
    window.WebSocket_PORT = data["ConfigVariables"]["WebSocket"]["WebSocket_PORT"];
    window.MAP_InforMation = data["MAP_InforMation"];
    window.currentMapname ="de_airstrip";
    window.mapInfo=new Object();
    var mapSocket = new WebSocket(`ws://${window.WebSocket_IP}:${window.WebSocket_PORT}`);
    
    mapSocket.onmessage = function(event) {
      try {
        window.jsonObject = JSON.parse(event.data);
        let update_sign = window.jsonObject["Update"]
        let map_name = window.jsonObject["MapName"]
       
        if(update_sign){
          UpdateMap(extractMapName(map_name));
          window.currentMapname = map_name;
        }
      } catch (error) {
        
      } 
    }
})
  .catch(error => {
    console.error('发生错误:', error);
  })

function setup(map_width=1024,map_height=768) {
    createCanvas(map_width, map_height);
    noStroke();
}
  function preload(imgName="loading.gif") {
    if(imgName == "loading.gif" && window.mapInitSign){
      setup();
    }
    window.img = loadImage(`http://${window.WebSocket_IP}/MapImage/${imgName}`);
  }
function draw() {
    background(window.img);
    translate(width / 2 , height / 2);
    
    try {
      if(!(typeof(window.mapInfo.map_center_distance_x) !="undefined" && Object.keys(window.jsonObject).includes("BOT0"))) {return};
    } catch (error) {
      return
    }
    
    push();
    scale(window.mapInfo.map_scale_ratio,-window.mapInfo.map_scale_ratio);
    
    for(i = 0; i < Object.keys(window.jsonObject).length; i++) {
      let x;
      try {
        x = window.jsonObject["BOT"+i]["X"]-(window.mapInfo.map_center_distance_x);
      } catch (error) {
        continue;
      }
      
      let y = window.jsonObject["BOT"+i]["Y"]-(window.mapInfo.map_center_distance_y);
    drawCircle(-y,x, 50, selectColor(window.jsonObject["BOT"+i]["F"]), window.jsonObject["BOT"+i]["HP"]);
    }
    pop();
    scale(window.mapInfo.map_scale_ratio);
    for(i = 0; i < Object.keys(window.jsonObject).length; i++) {
      try {
        x = window.jsonObject["BOT"+i]["X"]-(window.mapInfo.map_center_distance_x);
      } catch (error) {
        continue;
      }
      let y = window.jsonObject["BOT"+i]["Y"]-(window.mapInfo.map_center_distance_y);
    drawText(-y,x, 50, window.jsonObject["BOT"+i]["HP"]);
    drawBloodbar(-y,x, 50, window.jsonObject["BOT"+i]["HP"]);}
    
}


function drawCircle(x, y, size, c) { //人物圆点绘画
  try {
    fill(color(c));
    ellipse(x, y, size, size);
  } catch (q) {
    console.log("drawCircle发生未知的错误")
  }
 
}
function drawText(x, y, size, tene) { //人物血量绘画
  let yOffset = 10;
  textSize(100);
  textAlign(CENTER, TOP); 
  fill(255); 
  text(tene, x, -y + size / 2 + yOffset); 
}
function drawBloodbar(x, y, size,tene) { //人物血条绘画
  let yOffset = 10;
  let rectWidth = tene * 1.3;
  let rectHeight = 30;
  fill(255, 0, 0);
  rect(x - rectWidth / 2, -y - size / 2 - yOffset - rectHeight, rectWidth, rectHeight);
}
function parseColor(colorString) { //处理颜色数据
  let q;
  try {
    q = colorString.split(',').map(Number);
  } catch (error) {
    console.log("未知错误?");
  }
  
  return q ;
}
function selectColor(num) { //选择颜色
  return parseColor(window.Color[num]);
}
function UpdateMap(map_name){ //切换地图
  // alert('切换地图中!......');
  try {
    let info = window.MAP_InforMation["mapDisplayInformation"][map_name];
    window.mapInfo.map_center_distance_x = info['center_X']
    window.mapInfo.map_center_distance_y = info['center_Y']
    window.mapInfo.map_scale_ratio = info['scale_ratio']
    let rotaed_value = info['rotated']
    if(rotaed_value == 1){
      window.mapInfo.map_width = window.MAP_InforMation["mapDisplayInformation"]["map_height"]
      window.mapInfo.map_height = window.MAP_InforMation["mapDisplayInformation"]["map_width"]
    }else{
      window.mapInfo.map_width = window.MAP_InforMation["mapDisplayInformation"]["map_width"]
      window.mapInfo.map_height = window.MAP_InforMation["mapDisplayInformation"]["map_height"]
    }
    setup(window.mapInfo.map_width,window.mapInfo.map_height);
    preload(map_name);
  } catch (error) {
    return;
  }

}

function extractMapName(path){ //处理图片路径
  let incomplete = path.split("/").filter(function(item,index){
     return item.includes(".bsp")
  })
  return incomplete[0].replace(".bsp",".bmp");
}