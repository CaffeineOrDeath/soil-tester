# Pump

The pump system will be a simple water pump. Low pressure, cheap power
requirements. The idea here is one of two materials: stainless steel or a
peristaltic pump. One is corrosion resistant, the other can have the hose
replaced (cheaper in the long run).

The goal with the pump system is be as lightweight as possible while stuill
being durable enough to last a few uses or be easy to maintain. Replace rollers
or tubing instead of need to replace the whole pump system.

## Pump Type

From all of the research, I could only find two (2) options suitable for this
use case. Either a stainless steel pump to avoid corrosion and reduce maintance
or a peristaltic pump with anti-corrosive tubing. The problem with this is that
it needs to be flexible enough to handle repeated presure.

### Stainless Steel Pump

These pumps are naturally corrosive resitant. However, this adds significant
weight to the machine and would make it near impossible to move alone. The only
alternative to this method would be to use some type of motorized motion. At
that point, it would be more simple to code up a full computer system with eyes.
Not enough to be AI, but enough to do the job. 

The second problem with stainless pumps, is the cost. Starting at around
$350(USD), more than what the machine should cost in total. Even the smallest
version, is around $100(USD).

The third issue, is voltage requirement. Even a 1 phase stailess steel pump
requires 110V/50Hz. I'm not using mains voltage, so this is not a viable option
at this time.

### Peristaltic Pump

Lightweight, cheap to purchase, but not quite fitting what is required. These
pumps are relatively cheap. Around $12(USD) for a 12v dosing pump (medical use).
Once again, I don't need 12v. A small DC motor, should work just fine. I have
some basic hobby DC motors as well a 5v smart motor (CZ021-60028). I need to
find the data sheet for this motor to see what min-max settings it has. 

Pair a DC motor with bearings (for PoC, skateboard bearings) as the rollers
since I do not have the wheels for this. Solid rubber wheels, like a 3D printer
has, should be sufficient for this project. 

## Addendum

On top of those items, something is needed for the housing to hold the bearings
in place. For PoC, a 3D printed housing system, is probebly the best idea.
Clips together from both sides to make sure they fit. freeCAD for the design
software.
