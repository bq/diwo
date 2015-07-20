/*
*   
*   Description ........ 
*   by ........ 
*
*/

ui.toolbar.title("Temperature-Humidity");
ui.toolbar.bgColor(55, 155, 155, 255);
ui.toolbar.show(true);
//ui.screenMode("fullscreen");
ui.screenOrientation("portrait");
ui.allowScroll(false);
device.screenAlwaysOn(true);

var margin = 10;
var w = ui.screenWidth - 2*margin;
var h = 150 + margin;
var y = h + margin;

var btStatus=0; // Used to save the state of bt connection (0 or 1 - Not connected or connected)
var btClient; // object used to access bluetooth functions

var btnConnect = ui.addButton("Connect bluetooth", margin, margin,w,h).onClick(function() {
    
    btClient = network.bluetooth.connectSerial(function(status) {
        console.log("connected " + status);
        if (status){
            ui.toast("Connected");
            btStatus = status;
            console.log("btStatus = " +btStatus);
        }
    });
    
    btClient.onNewData(function(data) {
        parseIncomming(data); // "translate" data
        //Print Data in screen
        textH.setText(humidity + "%HR");
        textT.setText(temperature+"ºC");

        /* NEW */
        
        if(isAlarmSet && temperature>=tempAlarm){
            app.notification(01,"Temperature Alarm","Temperature is "+temperature+"ºC");
            if (!notification){
                device.vibrate(1000);
                media.playSound("glass_ping.mp3");
            }
            notification = true;
        }
        /* /NEW */
    });
});

var btnDisconnect = ui.addButton("Disconnect", margin, y,w,h).onClick(function() { // Creamos el botón de conectar
    btClient.disconnect(); 
    btStatus= false;
});

var humidity=0;
var temperature=0;
var debugging = false; // set true to see data in console

function parseIncomming (dataIn){
    if (debugging) console.log("dataIn ="+dataIn);
    var aux=dataIn/10000;
    if (debugging){
        console.log("aux=" +aux);
        console.log(parseInt(aux));
    }
    temperature= aux - parseInt(aux);
    temperature = (temperature * 100).toFixed(2);
    humidity = (aux/100).toFixed(2);
    if(debugging){
        console.log("temperature" + temperature);
        console.log("hum = "+humidity);
    }
}

/* MODIFIED POSITION AND SIZE*/
var textH  = ui.addText("Hum", margin +w/5, 2*y,w,2*h);
textH.textSize(50);
textH.color("#000000");
var textT  = ui.addText("Temp", margin +w/5, 3*y,w,2*h);
textT.textSize(50);
textT.color("#000000");
/* /MODIFIED */

/* NEW */
var timeToSend=0;
var flag;

var setIntervale = ui.addInput("Set intervale (s)", margin, 5*y, w/2, h).onChange(function(val){ 
    timeToSend = val * 1000; // From seconds to miliseconds
});

var setIntervaleBtn = ui.addButton("Set Intervale",margin +w/2,5*y,w/2,h).onClick(function(){
    flag = 1; // set flag to 1 to set intervale on Arduino
    send(flag,timeToSend);
});

var tempAlarm = 0;
var isAlarmSet = false;
var setAlarm = ui.addInput("Set Alarm (ºC)",margin,6*y,w/2,h).onChange(function(val){
    tempAlarm = val;
});

var notification = false; // change to true if a notification has been shown
var setAlarmCheck = ui.addToggle("Alarm",margin + w/2,6*y,w/2,h,false).onChange(function(val){
    isAlarmSet = val;
    if(!val){
        notification=false; // Change state to false when toggle is unchecked 
    }
});

function send(flag,value) { 
    if (btStatus) { 
        btClient.send(flag+","+value+"\n");
   }else{
       ui.toast("Not Connected");
   }
}

/* /NEW */



