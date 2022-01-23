# Customization

To get started, create a file called `nfsu2-rpc_lang.json` inside your scripts folder.  
It should look something like this:

```
scripts/
  nfsu2-rpc.asi
  nfsu2-rpc_lang.json
```

Now, open the file you have just created with your favorite text editor; I use VSCode, but SublimeText, Notepad++ or any other text editor will do it, even Windows Notepad.

At this point, if you are not familiar with JSON files, just do quick search.

As a starting point, copy the content of [`defaultLang.json`](/nfsu2-rpc/resources/defaultLang.json). It will give you an idea of the values you can customize.  
There will be three main sections:

## Cars

As the name may suggest, this object stores names for all cars in the game.  
Organization is fairly straightforward. keys are the cartypeinfo names that represent those specific cars, and values are the name you want them to show up as.

Lets say now that you want your `Nissan 240SX` to show up as `N1ss4n P0t4t0 SX :D`. All you have to do is find the corresponding key/value pair, which, in this case, is `240SX` and edit its value. It should end up looking something like this:

```json
    "240SX": "N1ss4n P0t4t0 SX :D",
```

The same applies to replacement cars, just do as shown above.  
If you are adding a new car to the game instead of replacing an existing one, you will want to add a new entry.

## Gamemodes

Stores fancy names for the gamemodes.

## Activity

This one is a bit different, since it contains 2 other objects inside of it. Those objects represent details and state, which are the first and second line of your activity, respectively.

You will notice that they both have the exact same keys, those keys represent the state the game is currently on.

One other difference compared to the previous two sections is that this one accepts placeholders, which are values that will later be replace with something else.

Placeholder   | Description
--------------|--------------------------------------------
\$car\$       | Car you are currently driving
\$track\$     | Track you are currently driving on
\$gamemode\$  | Gamemode
\$balance\$   | Your bank balance
\$profile\$   | Your in-game name
\$lobby\$     | Name of the lan lobby you are connected to

## For modders

If you own a mod or modpack and want things to show up correctly, you will have to distribute a `nfsu2-rpc_lang.json` or instruct your users.

If you decide to distribute a `nfsu2-rpc_lang.json` file, try to keep it minimal; include only the keys/values you actually need.

## Notes
- Weird characters, if not properly encoded, may cause the activity to not show up.
- It's okay if your `nfsu2-rpc_lang.json` file does not include every single key/value, as the mod will fallback the built-in language file.
