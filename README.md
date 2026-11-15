# Luma

Luma is a game streaming client for **mobile and desktop**, built on the
[Moonlight Game Streaming Project](https://github.com/moonlight-stream) and
compatible with NVIDIA GameStream and [Sunshine](https://github.com/LizardByte/Sunshine) hosts.

Main developer: [soleil-des-chats](https://github.com/Soleil-des-chats)

Luma is based on [Moonlight-Switch](https://github.com/XITRIX/Moonlight-Switch)
by XITRIX, and is distributed under the same license (GPL-3.0, see `LICENSE`).

## What's different

- A calmer look: deep violet palette, rounded corners, a softer focus ring, in light and dark mode.
- Touch first: bigger text and tap targets on phones and tablets, slimmer header and footer.
- Same layout and controls you already know, still fully usable with a gamepad or keyboard.

## Controls

- **Touch**: move the cursor, tap to left click, scroll with two fingers.
- **Keyboard**: tap with three fingers to show the on-screen keyboard. A physical keyboard also works.
- **Mouse**: supported.
- **Gamepad**: up to 5 gamepads. Key mapping is available in Settings.
- **In-game overlay**: opens with the configurable key combination (or hold ESC on a keyboard).

## Building

Clone with submodules:

```sh
git clone --recursive https://github.com/Soleil-des-chats/Luma.git
```

### iOS (unsigned IPA)

The **iOS Build (unsigned IPA)** GitHub Actions workflow (`.github/workflows/ios.yml`)
builds `Luma-unsigned.ipa`. Run it from the *Actions* tab (**Run workflow**), then
download the `Luma-iOS-unsigned-ipa` artifact.

The IPA is not signed. Sign and install it yourself with a tool such as
Sideloadly, AltStore, or your own certificate.

### Other platforms

See the workflows in `.github/workflows/` (Android, macOS, Windows, Linux) for the exact commands.

## Credits

- XITRIX, author of Moonlight-Switch
- The Moonlight team and Moonlight-Common-C
- Natinusala and contributors, for Borealis
- Rock88 and Moonlight-NX
