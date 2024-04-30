const { SameItem } = require('./comprseTools.js');
const net = require('net');
const mapSocket = require('nodejs-websocket');
const fs = require('fs');

let Socket_IP;
let Socket_PORT;
let WebSocket_IP;
let WebSocket_PORT;



(function(){
    fs.readFile(__dirname+"\\config.json",'utf8',function(err,data){
        if (err) {
            console.error('读取配置文件时发生错误:', err);
            process.exit(0)
          }
        data = JSON.parse(data);
        Socket_IP = data["ConfigVariables"]['Socket']['IP'];
        Socket_PORT = data["ConfigVariables"]['Socket']['PORT'];

        WebSocket_IP =data["ConfigVariables"]['WebSocket']['WebSocket_IP'];
        WebSocket_PORT = data["ConfigVariables"]['WebSocket']['WebSocket_PORT'];

        const serverOptions = {
            host: WebSocket_IP
        };

        var Mservers = mapSocket.createServer(serverOptions).listen(WebSocket_PORT)
        var server = net.createServer(); //Socket
        server.listen(Socket_PORT, function() {
            console.log(`Socket正在监听${Socket_PORT}端口`);
        });

        server.on('connection', function(socket) {
            console.log("新的连接进行...");
            socket.on('data', function(data) {
            Mservers.connections.forEach(item => { 
                let str = data.toString().split("|").filter(function(item,index){
                    return item=="" ? false:true
                });
                for(i=0;i<str.length;i++){
                    try{
                        item.send(str[i]);
                    }catch(error){
                        continue;
                    }
                }
            });
            });

            socket.on('close', function() {
                console.log("Client disconnected");
            });
        });

        server.on('error', function(error) {
            console.error("Server error:", error);
        });
    });
})();
