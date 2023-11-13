# Intel BackLIght ADjuster

I don't care how terrible this looks. I don't care (anymore) how to properly do this
within Xorg files or i3's config. I wrote this for myself so i can map my 
brightness up and down buttons to some utility I was familiar with. Also this was a neat
coding "challenge".

## Usage

```
ibliad +
```
Increases the brightness by 1 step.
```
ibliad - 
```
Decreases the brightness by 1 step.
```
ibliad +++
```
Increases the brightness by 3 steps.

As you can tell, it just counts how many `+` and `-` are given as arguments, and
increases/decreases the brightness accordingly. A "step" is the `max_brightness`
of your system divided by 20 (as defined in a macro).

### i3

This program was specifically created so that you could this into your i3 config:

```
bindsym XF86MonBrightnessDown exec "ibliad -"
bindsym XF86MonBrightnessUp exec "ibliad +"

```
Maybe you want to do so too.

I don't know how the config of any other window manager or so works.
You get the gist though.

## Requirements

I only wrote this for my own notebook, so this only works on notebooks with an 
Intel backlight, so only if the screen brightness is managed 
by `/sys/class/backlight/intel_backlight/`.

 - `/sys/class/backlight/intel_backlight/brightness` exists
 - `/sys/class/backlight/intel_backlight/max_brightness` exists
 - `max_brightness` is a value more than 20
 - Your user has writing permissions for `/sys/.../brightness`

If any of those requirements are not met, you can adjust the code and recompile it, e.g. by

 - Setting the `brightness` and `max_brightness` paths properly at the start of the file
 - Reducing the number of steps within the `STEPS` macro.
 - Doing something like `sudo chmod a+rw /sys/.../brightness`.


## Install
If you set up any peculiar things in a different way than usual, like a different compiler than
gcc, or a different `/bin` folder or a different location for your man pages,
you should adjust the `Makefile` first. Otherwise you are good to go.

After cloning the repository, do:
```
sudo make install
```

## Uninstall

```
sudo make uninstall
```

## Building for yourself
```
make
```
