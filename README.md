# Arduino-controlled HDMI switch - KiCad 10

# Sponsors wanted: help CentraleTech fabricate this PCB

**CentraleTech is looking for sponsors to fund PCB fabrication for this project. Your support will help us manufacture and test the board. Interested in sponsoring us? Please contact CentraleTech through our GitHub profile.**

Open Arduino-HDMI-Switch.kicad_pro, then its PCB or schematic.
This is a revised version of the supplied HDMI-Off board. A 5 V DPDT relay,
driven by an AO3400A MOSFET, replaces the manual switch. The Arduino GPIO
drives only the MOSFET gate; the relay coil runs from the 5 V supply.

## Wiring

Connect HDMI source to J1 and display to J2.
J3 pad 1 (square pad): Arduino regulated 5 V.
J3 pad 2: Arduino control GPIO, for example D8.
J3 pad 3: Arduino GND.
Use the PCB pad numbers: the older Prototype folder has a different pinout.
HIGH enables HDMI +5 V and Hot Plug Detect; LOW, floating control, or loss
of relay supply opens both relay contacts. Use a regulated 5 V supply for
the coil, not a GPIO or the Arduino VIN pin. 3.3 V or 5 V control is supported.
The coil supply must accommodate the selected relay's datasheet current.

## Design and assembly

K1: Omron G5V-2-H1 DC5, 5 V DPDT, Relay_DPDT_Omron_G5V-2 footprint.
Use the specified pinout and 5 V coil; check any substitute against its datasheet.
Q1: AO3400A in SOT-23; D3: 1N4148W in SOD-123, cathode toward +5 V.
D2: PMEG2010EA in SOD-323; D1: 3 mm green LED.
R1: 1.5 kohm; R2: 1 kohm; R3: 100 kohm, all 0805.
C1: 100 nF / 16 V; C2: 10 uF / 16 V, ceramic 0805.
J1/J2 retain the original HDMI footprint, bundled in HDMI_Switch.pretty.
Confirm the sockets you purchase match it. J3 is a 2.54 mm 3-pin header.
The board has FOUR copper layers and nominal 1.6 mm thickness.
Do not order it as a two-layer board.

## Checks performed

KiCad 10.0.8 ERC: 0 reported violations.
KiCad DRC after zone refill: 0 reported violations, 0 unconnected items,
and 0 PCB/schematic parity issues. See reports/ for the actual results.
Minimum copper clearance is 0.15 mm; copper-to-edge clearance is 0.25 mm.
The top board edge was extended by 0.1 mm to clear the existing clock trace.
All 168 original TMDS/DDC/CEC tracks, arcs and vias were compared and
preserved. The relay switches only HDMI pins 18 (+5 V) and 19 (HPD).
Gerbers and separate plated/nonplated drill files were regenerated from
this checked board. Silkscreen exports subtract solder-mask openings.
The project footprint paths now use KiCad's portable library variable.

The inherited project ignores missing courtyards, off-center via endpoints,
footprint filters, silk-over-mask, PTH/NPTH-inside-courtyard, and tuning
profile geometry checks; the DRC report lists these explicitly. Connectivity,
shorts and copper clearance checks are enabled. No individual DRC exclusions
are used. ERC also retains the ignored informational checks listed in ERC.json.

## Limits and first test

This is a CAD-checked design, not a physically tested unit. HDMI signal
integrity and operation at a particular resolution/refresh rate have not been
measured. The inherited stack-up is not a verified 100-ohm impedance design;
confirm its suitability with the board manufacturer before ordering for a
specific high-speed HDMI mode. Pin 14 remains unconnected as in the original;
ARC/eARC/HEC are not supported. Opening +5 V and HPD reproduces the original
switch function, but a guaranteed video blackout depends on source/display
behavior. No high-speed data lanes are disconnected.

Before connecting equipment, inspect soldering and check for power shorts.
With the Arduino supply on and HDMI cables disconnected, toggle D8 and check
that K1 pins 4-8 and 13-9 are open at LOW and closed at HIGH. D2 is in series
with HDMI +5 V, so use diode mode when checking that complete path.
Then test with an inexpensive HDMI source/display before valuable equipment.
The included .ino is a manual serial-command test: send 1 for ON, 0 for OFF.

## Files

- Arduino-HDMI-Switch.kicad_pro / .kicad_sch / .kicad_pcb: editable project.
- fabrication/: Gerbers, drill files and Gerber job.
- BOM.csv: assembly parts.
- reports/: KiCad ERC/DRC and independent connection listing.
- routing.svg: current layer preview. Existing PNG images are earlier previews.
