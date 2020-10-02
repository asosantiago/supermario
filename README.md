# recompile
Taller - Recompile
Gleylancer game


# Integrantes

* [Federico Funes](https://github.com/fedes79)
* [Francisco Ordoñez](https://github.com/ordonezf)
* [Ignacio Boada](https://github.com/NachoBoada)
* [Mauro Goñi](https://github.com/maurogoni)
* [Santiago Aso](https://github.com/santiagoaso)

# Pre-build
## Mac

```
brew install sdl2 sdl2_image sdl2_ttf
```

## Linux

```
#install sdl2
sudo apt install libsdl2-dev libsdl2-2.0-0 -y

#install sdl image
sudo apt install libjpeg-dev libwebp-dev libtiff5-dev libsdl2-image-dev libsdl2-image-2.0-0 -y

#install sdl mixer
sudo apt install libmikmod-dev libfishsound1-dev libsmpeg-dev liboggz2-dev libflac-dev libfluidsynth-dev libsdl2-mixer-dev libsdl2-mixer-2.0-0 -y

#install sdl true type fonts
sudo apt install libfreetype6-dev libsdl2-ttf-dev libsdl2-ttf-2.0-0 -y
```

# Build 

On mac
```
./compile mac
```
On Linux
```
./compile
```

# Command line
```
To use a custom configuration file use: --config file_name
To set a custom log level use: --log_level log_level

example: ./game --config game_configuration.json --log_level ERROR
```

# Debug

Only works on linux, needs `gdb` installed
```
./debug
```
