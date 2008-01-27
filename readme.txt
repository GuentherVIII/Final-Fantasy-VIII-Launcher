
FINAL FANTASY VIII LAUNCHER v1.31
Copyright (c) 2007 Tobias Sebring (aka Magix)



FEATURES
-----------------------------------------------------------------------------------------------------
- 8-bit Paletted Textures Fix for NVIDIA GeForce 6xxx+ graphics cards
- Custom Resolutions (including FSAA / Anisotropic Filtering Fix)
- Windows XP/Vista x86 Compatibility




INFORMATION
-----------------------------------------------------------------------------------------------------
FF8 Launcher injects a DLL into an FF8.exe process. The DLL hooks the DirectX COM interface of the
running process and is hence able to freely manipulate any and all DirectDraw/Direct3D calls being
made by the Game.

Final Fantasy VIII Launcher was originally a fix for the black texture corruption in Final Fantasy
VIII that is a result of newer generations of graphics hardware discontinuing their support for 8-bit
paletted textures.

Since the release of version 1.1 Final Fantasy VIII Launcher also features support for additional
resolutions to be used in the game.




INSTALLATION/USAGE
-----------------------------------------------------------------------------------------------------
Required files:
- FF8_Launcher.exe
- dx_hook.dll
- config.cfg

1. Move the included files (make sure to get at least the required files above) to a location of your
   choosing.

2. Run FF8_Launcher.exe instead of FF8.exe in the Final Fantasy VIII installation directory to play.


Opt. The FF8.exe path can be supplied as a command-line string in order to run it from an alternate
     location or in case the Final Fantasy VIII registry keys are missing and the launcher is unable
     to automatically find the executable by itself.

     Ex. C:\Games\Final Fantasy VIII\FF8_Launcher.exe C:\Games\Final Fantasy VIII\FF8.exe
     !NOTE! Do NOT use any quotes in the FF8.exe path.




OPTIONS
-----------------------------------------------------------------------------------------------------
Expert Mode (Enables advanced control of display properties):

TEXTURE UV-MAP COMPENSATION is used to remove line-artifacts on texture edges that appear in custom
resolution and FSAA settings. The default value for this setting is an average that works ok in most
configurations but a much better result can often be attained by manual adjustment.

There are two distinct values that control the compensation applied to background- and interface
textures respectively. Background textures are common in scenes (as opposed to field) and interface
textures in menus (character menu, main menu etc.)

- Decrease background-texture uv-map adjustment (ctrl+, [CTRL+COMMA])
- Increase background-texture uv-map adjustment (ctrl+. [CTRL+PERIOD])
- Decrease interface-texture uv-map adjustment (alt+, [ALT+COMMA])
- Increase interface-texture uv-map adjustment (alt+. [ALT+PERIOD])




VERSION HISTORY
-----------------------------------------------------------------------------------------------------
[ Version 1.31 ]
- New option "Stretch 4:3 Aspect Ratio" stretches the picture to the full screen width and height
  without maintaining original 4:3 picture aspect ratio. OPTION ONLY APPLIES TO NON-4:3 RESOLUTIONS.
- Added 1366x768 custom resolution.
- Fixed UV-map Compensation bug that made it impossible to remove all line-artifacts in background
  textures (very noticeable in wide-screen resolutions.)
- Fixed bug where the entire Black Borders Flicker Fix was not included in the release build of
  version 1.3 as intended.


[ Version 1.3 ]
- Vista x86 is now supported
- Non 4:3 aspect-ratio resolutions added. The display is padded with black borders to retain original
  4:3 picture aspect-ratio.
- Texture flickering on black borders fixed
- New option "Expert Mode" enables advanced control of display properties. See OPTIONS for more details.


[ Version 1.21 ]
- Additional custom resolutions have been added (1152x864, 1600x1200 and 2048x1536)
- FSAA / Anisotropic Filtering fix is now applied in 640x480 in addition to all custom resolutions from
  version 1.2


[ Version 1.2 ]
- Fix to compensate for the overlap caused by the inaccuracy of directx/hardware routines for texture
  filtering.
- All custom resolutions are now supported with practically no visible texture corruption and
  only minor artifacts.


[ Version 1.1 ]
New launcher interface and added support for setting custom resolutions. Suffered from major texture
corruption and glitches in all modes but 1920x1440.


[ Version 1.0 ]
First release; featured a fix for the 8-bit Paletted Textures incompatibility with NVIDIA GeForce 6xxx+
graphics cards.




KNOWN BUGS
-----------------------------------------------------------------------------------------------------
- Bink-videos that fade to black after the last frame are not scaled during the fade phase
- Textures on 3D objects that are mapped on four entirely flat (same z-coord) vertices flicker




KNOWN BUGS NOT CAUSED BY FINAL FANTASY VIII LAUNCHER
-----------------------------------------------------------------------------------------------------
- FSAA / Anisotropic Filtering settings in NVIDIA Control Panel are not applied on Vista
- Some custom resolutions do not work even though the system supports the given display mode
  (DirectX compatibility issue)
- "Black Screen of Death"-issue where the game will start but only display a black screen
  (Due to EAX acceleration no longer being supported in Vista - See FREQUENTLY ASKED QUESTIONS)




TESTED SYSTEMS
-----------------------------------------------------------------------------------------------------
C2D E6600, NVIDIA GeForce 8800GTX (ForceWare 163.75), Windows XP Pro. SP2
C2D Q6600, NVIDIA GeForce 8800GT (ForceWare 169.28), Windows XP
AMD Athlon X2 6000+, NVIDIA GeForce 8800GTS
C2D E6750, NVIDIA GeForce 8600GTS (ForceWare 169.21-BETA), Windows XP SP2
C2D T7100, NVIDIA GeForce 8600M GT, Vista Home Basic x86
C2D E6400, NVIDIA GeForce 7900GS 256MB (Forceware 163.75), Windows XP x64 SP2
AMD Athlon XP 64 2400, NVIDIA GeForce 7300GS
NVIDIA GeForce 6600GT, Windows XP
NVIDIA GeForce 6200, Windows XP SP2
ATI x800XT
NVIDIA Quadro FX Go1400



HELP/INPUT
-----------------------------------------------------------------------------------------------------
Refer to either of these forums:
http://forums.qhimm.com/index.php?topic=7248.0

http://forums.qhimm.com/index.php?topic=5731.0

http://forums.nvidia.com/index.php?s=4f6a203d58ea8ec84a133712055f0c99&showtopic=4908




FREQUENTLY ASKED QUESTIONS
-----------------------------------------------------------------------------------------------------
Q: What are the system requirements for the Final Fantasy VIII Launcher?

A: Windows XP and Vista x86.
   There's NO support for Windows versions earlier than XP (98/98SE/ME etc.)



Q: I have a widescreen LCD monitor, NVIDIA GeForce 8800 graphics card and Windows XP. How do I avoid
   the image being stretched in non-native resolutions or aspect ratios?

A: 1. Download and install this patch from the NVIDIA knowledge base:
      http://nvidia.custhelp.com/cgi-bin/nvidia.cfg/php/enduser/std_adp.php?p_faqid=2064

   2. Change the flat panel scaling option under the NVIDIA Control Panel to "Do not scale".
      !NOTE! This option will reset and malfunction after having opened an application utilizing
      video mixer functionality (ex. Windows Media Player, VLC).



Q: The game crashes ("Black Screen of Death") on Vista x86. What do I do?

A: This is due to EAX acceleration no longer being supported in Vista.
   If you have a Creative Audigy or X-Fi Soundcard; Creative supplies an application called
   "Creative ALchemy" that translate audio calls from DirectSound3D (EAX) to OpenAL.

   The application can be found here: http://connect.creativelabs.com/alchemy/default.aspx

   Owners of non-Creative brand Soundcards should check their manufacturer homepage for a possible
   workaround. Disabling EAX/sound acceleration or in worst case, uninstalling the soundcard drivers,
   should fix this issue. The latter would result in no sound.



Q: The game won't start in resolution x but my display supports it. Why not?

A: From what I can tell this is a backwards compatibility issue with Direct3D 6.1. The issue is common
   to all applications using the same version of Direct3D. No fix is currently known.




DISCLAIMER
-----------------------------------------------------------------------------------------------------
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT
LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL TOBIAS SEBRING OR ANY OTHER CONTRIBUTOR BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.