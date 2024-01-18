# Description

## Components
- 2 resin hearts
- 2 PCBs
- 2 batteries

## Deployment
1. Open the covers of the 2 hearts.
2. Ensure the PCBs are properly connected to each battery.
3. Turn the PCB switch to ON.

   ![turn on the pcb](https://github.com/MarineReynaud25/HeartBit/blob/main/turnonpcb.png)

5. Close the cover.
6. Display the 2 pendants.
7. Press the button on one heart to light up the other.

## Debugging
If communication between the two boards stops working:
- Make sure the lithium battery is sufficiently charged. You can charge it with the Lipo charger Type C(V1.0).

   ![charge the battery](https://github.com/MarineReynaud25/HeartBit/blob/main/charge.png)

- Reload the Arduino code below onto the board, being careful with the macAdress (see the macAdress file for the code).
- If the LEDs do not light up correctly, turn off the PCBs, wait a moment, then turn them back on.
