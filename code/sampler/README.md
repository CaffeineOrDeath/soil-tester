# Sampler

The `Sampler` portion of this project is responsible for extracting and storing
the soil sample in a tube. The `Sampler` will handle the control of a motor. 
This motor will either be weighted offset from the shaft to add vibration to 
drive the extractor and/or a single drive system, like an extruder for a 3D
printer. This should contain enough force to move the tube down into the soil.

## Plan

The `Sampler` motor needs to work. There are many types of motors and motor
controllers, however we really only need enough force to penatrate roughly
6"/15cm/150mm. 

As to extract, I do not know for certain the best apporach. I am considering a
vacuum system, however I'm not positive on a viable storage container to handle
low pH solutions. Surely, PET plastic should be sufficent.

After the extraction and subsequent filling of the container, the container can
either be stored in the machine and extracted indoors (optional as this would
only really matter if it is wet outside) or extracted from the machine at the
site. 

## Addendum

Having considered the extraction procedure, there is a very high chance that
using a weighted offset motor would be the best option as this will allow it to
drive the tube into the ground, retrieve it, dry it using heating elements, and
drop it into a vial via vibration from the motor. This method would alleviate
the problem of trying to use an alterntive method.
