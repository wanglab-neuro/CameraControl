# CameraControl
Resources for controlling video acquisition.

## TTL trigger

**Teensy Trigger Module**  
Code for a Teensy-based camera trigger module.  
	See module documentation [here](https://osf.io/nvrjy/?view_only=6086cd790d8e4aeeb442e7f3d0f9bf42).    
	__  
	Basic version:  
		Use the code _TeensyCamTrigger_DigInLogicControl_500Hz_ .  
		The Teensy waits for a logic high on `syncTrigPin`, then sends TTLs throug `syncPin` at 500Hz, until `syncTrigPin` goes low.  
		Adjust the code (pins, frequency) to suit your needs.  

 
## Basler camera settings  
Configuration files for Basler cameras. 

## Bonsai
Workflows for recording videos with Bonsai.
- Install [Bonsai](https://bonsai-rx.org/). Go to the Package Manager and install libraries for video acquisition: Vision / Video / Visualizers.  Also install a library for interfacing with your camera (Pylon for Basler Cameras, PCO for PCO cameras, etc)
- [optional] Install [ffmpeg](https://ffmpeg.org/download.html). Most video recording workflow will require ffmpeg. The `essentials` release version is sufficient. For Windows, you can use the builds from [gyan.dev](https://www.gyan.dev/ffmpeg/builds/).
- Configure your camera settings in the camera's default configuration editor (e.g., [Pylon Viewer](https://www.baslerweb.com/en/products/software/basler-pylon-camera-software-suite/pylon-viewer/), or use one of the configuration files from this repository. For Basler cameras, use Pylon version 5.0 (more recent version won't work at the moment). 
- Open the workflow. In the camera acquisition node (e.g., PylonCapture), select the configuration file for that camera. 


