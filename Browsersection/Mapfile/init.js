(function(){
    const fs = require('fs');
    const os = require('os');
    const chalk = require('chalk');
    const networkInterfaces = os.networkInterfaces();
    const readlineSync = require('readline-sync');
    
    
    if(fs.existsSync(__dirname+"\\config.json")){
        let alredayFile = readlineSync.question(chalk.red("The configuration file already exists. Do you want to regenerate it(yes/no):"))
        if(alredayFile == "no" || alredayFile == ''){
            process.exit(0)
        }
    }
    let WebSocket_IP;
    let Socket_IP;
    let numberInit=0;
    let NetworkJson ={};
    for(interfaceData in networkInterfaces){
        console.log(numberInit,networkInterfaces[interfaceData][1]["address"])
        NetworkJson[numberInit] = networkInterfaces[interfaceData][1]["address"];
        numberInit++;
    } 
    while(true){
        Socket_IP = NetworkJson[readlineSync.question("Select Socket_IP address (number) = ")]
        WebSocket_IP = NetworkJson[readlineSync.question("Select WebSocket_IP address (number) = ")]
        if(WebSocket_IP && Socket_IP){
            break;
        }
        console.log(chalk.red("According to numbers!"))
    }
    data = {
        "init":"1",
        "MAP_InforMation":{
            "resolvingPower":{
                "weight":"1024",
                "height":"768"
            },
            "mapDisplayInformation":{
                "map_width":"1024",
                "map_height":"768",
                "cs_assault.bmp":{
                    "center_X":"-531",
                    "center_Y":"1390",
                    "scale_ratio":"0.26",	
                    "rotated":"0"
                },
                "cs_italy.bmp":{
                    "center_X":"-212",
                    "center_Y":"243",
                    "scale_ratio":"0.22",
                    "rotated":"0"
                },"de_dust.bmp":{
                    "center_X":"101",
                    "center_Y":"1071",
                    "scale_ratio":"0.152",
                    "rotated":"0"
                },"de_dust2.bmp":{
                    "center_X":"-223",
                    "center_Y":"1097",
                    "scale_ratio":"0.187",
                    "rotated":"0"
                },"de_airstrip.bmp": {
                    "center_X": "-1106",
                    "center_Y": "-386",
                    "scale_ratio": "0.155",
                    "rotated": "0"
                },
                "de_cbble.bmp":{
                    "center_X":"-959",
                    "center_Y":"312",
                    "scale_ratio":"0.155",
                    "rotated":"0"
                },"de_cpl_mill.bmp":{
                    "center_X":"511",
                    "center_Y":"1769",
                    "scale_ratio":"0.185",
                    "rotated":"0"
                },"de_cpl_fire.bmp":{
                    "center_X":"616",
                    "center_Y":"-352",
                    "scale_ratio":"0.18",
                    "rotated":"1"
                },"de_aztec.bmp":{
                    "center_X":"-347",
                    "center_Y":"-172",
                    "scale_ratio":"0.1729",
                    "rotated":"1"
                },"de_inferno.bmp":{
                    "center_X":"490",
                    "center_Y":"1280",
                    "scale_ratio":"0.187",
                    "rotated":"1"
                },"de_nuke.bmp":{
                    "center_X":"264",
                    "center_Y":"-912",
                    "scale_ratio":"0.155",
                    "rotated":"1"
                },"de_prodigy.bmp":{
                    "center_X":"1623",
                    "center_Y":"-272",
                    "scale_ratio":"0.28",
                    "rotated":"1"
                },"de_train.bmp":{
                    "center_X":"32",
                    "center_Y":"156",
                    "scale_ratio":"0.195",
                    "rotated":"1"
                },"de_vertigo.bmp":{
                    "center_X":"-1280",
                    "center_Y":"-256",
                    "scale_ratio":"0.3",
                    "rotated":"1"
                },
                
            }
        }
        ,
        "ConfigVariables":{
            
            "Socket":{
                "IP":Socket_IP,
                "PORT":"8083"
            },"WebSocket":{
                "WebSocket_IP" :WebSocket_IP,
                "WebSocket_PORT":"8085"
            }
        },
        "G_attribute":{
            "Color":{
                "enemy":"255, 0, 0",
                "self":"128, 0, 128",
                "teammate":"0, 0, 255"
            }
        }
    }
    fs.writeFileSync(__dirname+"\\config.json",JSON.stringify(data));
    console.log(data);
    console.log(chalk.yellow("配置文件所在路径:"+__dirname+"\\config.json"))
    readlineSync.question();
    
})()
