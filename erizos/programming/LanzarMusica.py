import subprocess 
import serial
import glob
import sys
import Tkinter
import tkMessageBox
#input('Please press enter when usb is connected.')


port=''.join(glob.glob("/dev/ttyUSB*"))  #buscar todos los puertos USBx y devolver en lista, convertir a string para conectar

print port
arduino=serial.Serial(port,9600)

window=Tkinter.Tk()
window.wm_withdraw()
tkMessageBox.showinfo(title="Info", message="Close this message box and press the button on the table")


flag=0
while flag==0:
	msg = arduino.readline()
	print msg
	if msg=='play\n' :
		command='vlc ../data'
		subprocess.Popen(command.split())
		#arduino.write("start")
		flag=1


		
