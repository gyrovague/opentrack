opentrack project home at <<http://github.com/opentrack/opentrack>>.

Binary releases at <<https://github.com/opentrack/opentrack/releases>>.

Please first refer to <<https://github.com/opentrack/opentrack/wiki>>
for new user guide, frequent questions, specific tracker/filter
documentation.

[![user support](https://badge.waffle.io/opentrack/opentrack.svg?label=support&title=User%20issues)](http://waffle.io/opentrack/opentrack)
[![not started](https://badge.waffle.io/opentrack/opentrack.svg?label=ready&title=TODO)](http://waffle.io/opentrack/opentrack)

***

**opentrack** is an application dedicated to tracking user's head
movements and relaying the information to games and flight simulation
software.

Not to be confused with railway planning software <<http://opentrack.ch>>

***

# Tracking sources

- PointTracker by Patrick Ruoff, freetrack-like light sources
- Oculus Rift DK1, DK2 and legacy versions
- Paper marker support via the ArUco library <<https://github.com/rmsalinas/aruco>>
- Human face tracker <<https://github.com/sthalik/headtracker>>
- Razer Hydra
- Relaying via UDP from a different computer
- Relaying UDP via FreePIE-specific Android app
- Joystick analog axes (Windows, Linux)
- Windows Phone [tracker](http://www.windowsphone.com/en-us/store/app/opentrack-head-tracking/1c604f32-6d68-40ef-aa44-3163e30f547f) over opentrack UDP protocol
- Arduino with custom firmware
- Intel RealSense 3D cameras (Windows)

# Output

- SimConnect for newer Microsoft Flight Simulator (Windows)
- freetrack implementation (Windows)
- Relaying UDP to another computer
- Virtual joystick output (Linux, Windows)
- Wine freetrack glue protocol (Linux, OSX)
- X-Plane plugin (Linux)
- Tablet-like mouse output (Windows)
- FlightGear Nasal script
- FSUIPC for Microsoft Flight Simulator 2002/2004 (Windows)

***

# Configuration

**opentrack** allows for output shaping, filtering, the codebase builds
on on Microsoft Windows, Apple OSX, and GNU/Linux.

Don't be afraid to submit an issue/feature request if need arises.

***

# Credits

- Stanisław Halik (maintainer)
- Chris Thompson (aka mm0zct)
- Donovan Baarda (filtering/control theory expert)
- Ryan Spicer (OSX tester, contributor)
- Patrick Ruoff (PT tracker)
- Ulf Schreiber (PT tracker)
- Xavier Hallade (RealSense tracker)
- furax49 (hatire tracker)
- Andrzej Czarnowski (quality assurance)
- uglyDwarf (high CON)
- Wim Vriend (historically)

# Licensing information

Almost all code is licensed under the [ISC license](https://en.wikipedia.org/wiki/ISC_license). There are very few proprietary dependencies. There is no copyleft code. See individual files for licensing and authorship information.
