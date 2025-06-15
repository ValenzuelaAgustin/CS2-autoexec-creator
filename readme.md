# CS2 Autoexec Generator

This tool generates an `autoexec.cfg` file for Counter-Strike 2 by extracting settings from the configuration files created by the game. It allows players to centralize, edit, and reuse their custom settings consistently across different systems or installations.

## Why Use an Autoexec?

Counter-Strike 2 stores user settings in `.vcfg` files, distributed across multiple files depending on the type of configuration (machine settings, user settings, key bindings). These files are not easily portable, and some settings may be overridden or reset depending on game updates or system changes.

An `autoexec.cfg` file is a traditional and reliable way to:

- Ensure key settings are consistently applied every time the game launches.
- Maintain a personal configuration file that is independent from game updates.
- Share and version-control configuration files across different systems or users.

## About the Tool

The tool includes a precompiled executable: `autoexec-creator.exe`. When executed, it reads the `.vcfg` files from the CS2 configuration directory and creates a corresponding `autoexec.cfg` file.

### Included Settings

The generated `autoexec.cfg` includes every setting that can be adjusted from the in-game **Settings menu**, with the exception of video settings. Specifically, it covers:

- Audio settings
- Game settings
- Keyboard and Mouse settings (including key bindings and sensitivity)

In addition to these, the tool also extracts several commonly used advanced or UI-related settings, such as:

- `viewmodel_fov`
- `viewmodel_offset_x`
- `viewmodel_offset_y`
- `viewmodel_offset_z`
- `hud_showtargetid`
- `cl_radar_icon_scale_min`
- `cl_crosshair_dynamic_splitdist`
- `cl_crosshair_dynamic_splitalpha_innermod`
- `cl_crosshair_dynamic_splitalpha_outermod`
- `cl_crosshair_dynamic_maxdist_splitratio`
- `cl_fixedcrosshairgap`

> Video settings are intentionally excluded, as they are often system-specific and best left to the game's own graphics configuration tools.

### Key Bindings

- The tool reads **all key bindings** found in the configuration file, including those bound to unknown or custom commands. This ensures that personal scripts and nonstandard key mappings are not ignored.
- However, it has been observed that for some players, **key bindings are not stored in **. In such cases, the user must manually add their key bindings to the generated `autoexec.cfg`.
- It is **recommended** to include an `unbindall` command at the top of the key bindings section to avoid conflicts with the game's default bindings. The tool does not include this by default.

### Workaround for Missing Bindings

If your key bindings are not being read from `cs2_user_keys_0_slot0.vcfg`, you can provide them manually using the following method:

1. Navigate to the directory where your `.vcfg` files are stored:
   ```
   ...\Steam\userdata\YOUR_USER_ID\730\local\cfg\
   ```
2. Make a copy of your existing `autoexec.cfg` file that contains your current bindings.
3. Rename the copied file to:
   ```
   cs2_user_keys_0_slot0.vcfg
   ```
4. Ensure the format of the bindings in that file is compatible. Each bind line must follow this exact format:
   ```
   bind "key" "command"
   ```
   - Both the key (input) and the command must be enclosed in **double quotes**.
   - There should be **no extra spaces inside the quotes** or between the command elements.
   - Correct: `bind "w" "+forward"`
   - Incorrect examples:
     - `bind "w" +forward`
     - `bind "w" " +forward "`
     - `bind w "+forward"`

Following these steps will allow the program to read your keybindings from the renamed file as if it were the original `.vcfg`.

### Output Behavior

- The output file is always named `autoexec.cfg`.
- If a file named `autoexec.cfg` already exists in the output directory, it will be **overwritten** without warning.
- It is recommended to back up any existing `autoexec.cfg` before running the tool.

## Input Files

The tool reads the following files from the CS2 configuration directory:

- `cs2_machine_convars.vcfg`
- `cs2_user_convars_0_slot0.vcfg`
- `cs2_user_keys_0_slot0.vcfg`

Location:

```
...\Steam\userdata\YOUR_USER_ID\730\local\cfg\
```

Replace `YOUR_USER_ID` with your actual Steam numeric ID.

## Output File

The generated `autoexec.cfg` can be placed in the game's config folder:

```
...\Counter-Strike Global Offensive\game\csgo\cfg
```

To ensure the file is executed at game launch, add the following to your launch options in Steam:

```
+exec autoexec.cfg
```

## Usage

### 1. Run the executable

Place `autoexec-creator.exe` in the same folder as the `.vcfg` files (see path above), then run it. A new `autoexec.cfg` file will be created in the same directory.

### 2. Move the file

Manually copy `autoexec.cfg` to your CS2 configuration directory (see path above).

## Notes

- The original `.vcfg` files are not modified by this tool.
- Only editable settings exposed in the game’s UI or commonly used by the community are extracted (excluding video settings).
- If key bindings are missing from the generated file, it may be due to them not being saved in `cs2_user_keys_0_slot0.vcfg`; manual inclusion will be required in such cases.
- The generated `autoexec.cfg` file can be freely edited after creation.

## License

This project is licensed under the MIT License.