
ui.toolbar.title("Sensors");
ui.toolbar.bgColor(55, 155, 155, 255);
ui.toolbar.show(true);
//ui.screenMode("fullscreen");
ui.screenOrientation("portrait");
ui.allowScroll(false);

var margin = 10;
var w = ui.screenWidth - 2*margin;
var h = 150;
var y = h + margin;

var accelerometer   = ui.addText(margin, margin, w, h);
var orientation     = ui.addText(margin, 0.5*h + margin, w, h);
var light           = ui.addText(margin, 1*h + margin, w, h);
var gyroscope       = ui.addText(margin, 1.5*h + margin, w, h);
var magnetic        = ui.addText(margin, 2*h + margin, w, h);
var barometer       = ui.addText(margin, 2.5*h + margin, w, h);
var proximity       = ui.addText(margin, 3*h + margin, w, h);

var acelX,acelY,acelZ;

sensors.accelerometer.onChange(function(x, y, z) {
    
    accelerometer.setText("acc: "+ toFixed(x,2)+ ", " +toFixed(y,2)+ ", " + toFixed(z,2));
    acelX = x;
    acelY = y;
    acelZ = z;

});


sensors.orientation.onChange(function(pitch, roll, yaw) {
   orientation.setText("orientation: " + toFixed(pitch,2) + ", "+ toFixed(roll,2) + ", " + toFixed(yaw,2) );
});

sensors.lightIntensity.onChange(function(intensity) {
   light.setText("light: " + intensity);
});

sensors.gyroscope.onChange(function(x, y, z) {
   gyroscope.setText("gyro: " + toFixed(x,2)+ ", " + toFixed(y,2) + ", " + toFixed(z,2) );
});

sensors.magnetic.onChange(function(x, y, z) {
   magnetic.setText("magnetic: " + toFixed(x,2));
});

sensors.pressure.onChange(function(x) {
   barometer.setText("barometer " + x);
});

sensors.proximity.onChange(function(intensity) {
   proximity.setText("proximity: " + intensity);
});

sensors.stepDetector.onChange(function() {
    console.log("step detected");
});

var state = false;

var btnPlay = ui.addButton("Play",margin,ui.screenHeight - 3*h, w, h).onClick(function(){
    
    if (!state){
        
        accelerometer.setAlpha(0);
        orientation.setAlpha(0);
        light.setAlpha(0);
        gyroscope.setAlpha(0);
        magnetic.setAlpha(0);
        barometer.setAlpha(0);
        proximity.setAlpha(0);
        
        canvas.setAlpha(255);
        
        state = !state;
        btnPlay.setText("Pause");
        
    }else{
        
        accelerometer.setAlpha(255);
        orientation.setAlpha(255);
        light.setAlpha(255);
        gyroscope.setAlpha(255);
        magnetic.setAlpha(255);
        barometer.setAlpha(255);
        proximity.setAlpha(255);
        
        canvas.setAlpha(0); 
        canvas.clear();
        canvas.background(0,0,0);
        state = !state;
        btnPlay.setText("Play");
    }
    
});

var wCanvas =  ui.screenWidth -4*margin;
var hCanvas = ui.screenHeight - 3.5*h;

var canvas = ui.addCanvas(2*margin, margin, wCanvas, hCanvas);
canvas.background(0,0,0);
ui.alpha(canvas,0);

canvas.loopDraw(50, function() {

    canvas.fill( randomColor(),randomColor(),randomColor());
    var size = randomSize();
    canvas.ellipse(posX(acelX),posY(acelY),size,size);

});

function randomColor(){
    
    return Math.random() * 255;
}

function posX(value){
    return value*wCanvas/9.81;
}

function posY(value){
    return value*hCanvas/9.81;
}

function randomSize(){
    return Math.random()*wCanvas/2;
    
}

function toFixed(value, precision) {
    var power = Math.pow(10, precision || 0);
    return String(Math.round(value * power) / power);
}


//Protocoder automagically stops all the sensors 
//when you exit your script, but here you have a 
//handy function to stop them all :)
function stopAll() {
    sensors.accelerometer.stop();
    sensors.orientation.stop();
    sensors.lightIntensity.stop();
    sensors.gyroscope.stop();
    sensors.magnetic.stop();
    sensors.pressure.stop();
    sensors.proximity.stop();
    sensors.stepDetector.stop();
}





