# CameraControl
Resources for controlling video acquisition.

## TTL trigger

**Teensy Trigger Module**  
Code for a Teensy-based camera trigger module.  
	See module documentation here: https://osf.io/nvrjy/?view_only=6086cd790d8e4aeeb442e7f3d0f9bf42  
	__  
	Basic version:  
		Use the code _TeensyCamTrigger_DigInLogicControl_500Hz_ .  
		The Teensy waits for a logic high on `syncTrigPin`, then sends TTLs throug `syncPin` at 500Hz, until `syncTrigPin` goes low.  
		Adjust the code (pins, frequency) to suit your needs.  

 
## Basler camera settings  
(TBD)  
