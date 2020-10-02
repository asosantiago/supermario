# Pre-build
## Mac

```
brew install sdl2 sdl2_image sdl2_ttf
```

# Build 

On mac
```
./compile mac
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
