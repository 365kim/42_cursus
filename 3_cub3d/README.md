# cub3D

### :bulb: Evaluation Log

1. 20/11/10
 - **108 score** _(mandatory 100 + bonus 8)_

---

### :bulb: Objective

- to explore `raycasting` with `miniLibX` by creating 3D graphical representation from a 1st person perspective.
- to improve skills in windows, colors, events and fill shapes with the help of `basic algorithms` and `information research`.

---

### :bulb: Files Turned In

0. Preview

   - Test the original game [here](http://users.atw.hu/wolf3d/)
     ![image](https://user-images.githubusercontent.com/60066472/95551029-ea4e8380-0a44-11eb-9931-68307f7128aa.png)

- What is miniLibX?
  - A small homemade library, which will allow you to open windows on the screen and make pretty drawings inside.
  - `man mlx` : how it works
  - `man mlx_new_window` : how to manage windows
  - `man mlx_pixel_put` : how to draw inside the window
  - `man mlx_new_image` : how to manipulate the images
  - `man mlx_loop`

1. Mandatory Part

    - [***Makefile***](./Makefile)
    - [***cub3d.h***](./srcs/cub3d.h)
    - [***cub3d.c***](./srcs/cub3d.c)
    - [***f01_read_info.c***](./srcs/f01_read_info.c)
    - [***f02_read_map.c***](./srcs/f02_read_map.c)
    - [***f03_validate_info_map.c***](./srcs/f03_validate_info_map.c)
    - [***f04_rearrange_all.c***](./srcs/f04_rearrange_all.c)
    - [***f05_set_sprite.c***](./srcs/f05_set_sprite.c)
    - [***f06_run_program.c***](./srcs/f06_run_program.c)
    - [***f07_execute_raycasting_loop.c***](./srcs/f07_execute_raycasting_loop.c)
    - [***f08_set_background.c***](./srcs/f08_set_background.c)
    - [***f08_set_background.c***](./srcs/f08_set_background.c)
    - [***f10_raycast_sprite.c***](./srcs/f10_raycast_sprite.c)
    - [***f11_take_screenshot.c***](./srcs/f11_take_screenshot.c)

2. Bonus

- At least 14 of them must be validated to to earn ALL bonus points
  - [01] Wall collisions.
  - [02] A skybox.
  - [03] Floor and/or ceiling texture.
  - [04] An HUD(heads-up display).
  - [05] Ability to look up and down.
  - [06] Jump or crouch.
  - [07] A distance related shadow effect.
  - [08] Life bar.
  - [09] More items in the maze.
  - [10] Object collisions.
  - [11] Earning points and/or losing life by picking up objects/traps.
  - [12] Doors which can open and close.
  - [13] Secret doors.
  - [14] Animations of a gun shot or animated sprite.
  - [15] Several levels.
  - [16] Sounds and music.
  - [17] Rotate the point of view with the mouse.
  - [18] Weapons and bad guys to fight!

---

### :bulb: Check if...

- Executable name & Configuration file

  - the project compiles well (without re-link) when excuting the **make** command and that the executable name is **cub3D**
  - the formatting is as described in the subject
    - image resolution/window size - R
    - north texture path - NO
    - east texture path - EA
    - south texture path - SO
    - west texture path - WE
    - sprite texture path - S
    - floor color - F
    - ceilling color - C
    - the map (see subject for the map configuration details)
  - the program returns an error and exits properly when the configuration file is misconfigured (i.e. an unknown key, double keys, or an invalid path) or if the filename doesn't end with the **.cub** extension.

- Technical elements of the display (5)

  - the program opens a window at the launch of the program when the **--save** argument is not supplied with the resolution as set in the configuration file.
  - the image representing the maze is displayed inside the window.
  - the program does not open a window when the **--save** arguemnt is supplied, and output **.bmp** file with the resolution as defined in the configuration file (R key).
  - the content of the window remains consistent while hiding a part of the window, minimizing the windows and maximizing it back.
  - the program resizes the window to fit the screen resolution, if the resolution in the config file greater is than the actual screen resolution.

- User basic events (3)

  - the program closes the window and exit cleanly, when clicking the red cross at the top left of the window.
  - the program closes the window and exit cleanly, when pressing ESC key (or Q)
  - the program renders a visible result on the window, such as a player's movement/rotation, when pressing 4 arrow keys (or WASD / ZQSD)

- Movements (4)

  - the player's spawning orientation on the first image is in accordance with the configuration file, test for each cardinal orientation (N, S, E, W).
  - the player's view rotates to the left then to the right as if the player’s head was moving, when pressing the left arrow (or A or Q) then the right arrow (or D)
  - the player's view goes forward and then backward in a straight line, when pressing the up arrow (or W or Z) then the down arrow (or S).
  - during those four movements, the display is smooth enough for the game to be "playable".

- Walls & Sprites (5)

  - the walls texture varies depending on which compass point the wall is facing (north, south, east, west).
  - it actually modifies the rendered texture or sprite, if modifying the path of a wall texture or sprite image in the configuration file and re-execute the program.
  - it raises an error if you set a non-existant path.
  - the sprite is displayed correctly and that it can be present multiple times in the same map.
  - the colors of the floor and the ceilling are well handled when you modify them in the configutation file.

- Error management (4)

  - numerous arguments and random values don’t alternate or create unhandled errors.
  - there is no memory leak.
  - the program shows any strange behaviors and it must stay functional, when rolling your arm on the keyboard.
  - the program does not show any strange behaviors and it must stay functional if the map is well configured, if not it must raise an error.

### :bulb: Useful Links

- [Complete list of AppleScript key codes](https://eastmanreference.com/complete-list-of-applescript-key-codes)
- [Virtual Keycodes for the Mac QWERTY Layout](http://www.meandmark.com/keycodes.html)
- [mlx Tutorial](https://github.com/taelee42/mlx_example)
- [Clipart Library](http://clipart-library.com/)
- [Convertio - PNG to XPM](https://convertio.co/kr/pricing/?utm_source=hit_dm)
- [Raycasting Tutorial(Korean) - Background](https://github.com/365kim/raycasting_tutorial)
- [Raycasting Tutorial(Korean) - Sprite](https://github.com/l-yohai/cub3d)
