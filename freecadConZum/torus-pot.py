#-------------------------------------------------
#-- BQ Human rights to technology
#--    Tienes derecho a la tecnologia
#-------------------------------------------------
#-- Released under the GPL license
#-- March, 2015
#-------------------------------------------------
#-- Alvaro Ferran
#-- Juan Gonzalez (Obijuan)
#-------------------------------------------------
#-- Move a Torus using an external potentiometer
#--  connected to the zum board (arduino compatible)
#--
#--  1) upload the firmware pot-server.ino into
#--      the zum / arduino board
#--  2) Connect a potentiometer in the A0 pin
#--  3) Set the serial port in the SERIAL_NAME
#--  4) Connect the zum / arduino board
#--  5) Execute this script!
#--  6) Have fun!
#--------------------------------------------------

from PySide import QtCore
import serial
import time

#-- Configure the serial port here
#-- Windows: Use COMx
#-- Linux: Use /dev/ttyUSB*, /dev/ttyACM*, /dev/rfcomm*
SERIAL_NAME = "/dev/ttyUSB0"


#---------------------------------------
#- This function is called periodically
#- for updating the object rotation
#---------------------------------------
def update():
	
	#-- Ask the zum board for another sample
	zum.write('\n')

	#-- Read the sample and convert it to angle between 0 - 180 degrees
	angle = 180 * float(zum.readline()) / 1023.
	print("Angle: {}".format(angle))
	
	#-- Change the torus rotation
	rot = App.Rotation(App.Vector(1,0,0),angle)
	Torus.Placement.Rotation = rot
	
	if angle == 0:
		timer.stop()
		print("FINISHED!")
	
	return

#-- Open the serial port
zum = serial.Serial(SERIAL_NAME,19200, timeout = 0.2)
print("Openning serial port...")

#-- Create a new freecad document
doc = App.newDocument("Example")

#-- Add a Torus
Torus = doc.addObject("Part::Torus","Torus")
doc.recompute()

#-- Change the view
Gui.SendMsgToActiveView("ViewFit")
Gui.activeDocument().activeView().viewAxometric()

#-- Wait some time for the zum to boop up
time.sleep(2)

#-- Setup the timmer for upting the object periodically
timer = QtCore.QTimer()
timer.timeout.connect(update)

#-- Start!
timer.start(50)
