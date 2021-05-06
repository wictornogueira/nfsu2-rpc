# Create directories
New-Item -ItemType Directory -Force -Path "build\scripts" | Out-Null
New-Item -ItemType Directory -Force -Path "dist\" | Out-Null

# Compile
& i686-w64-mingw32-g++.exe -I src\ -I include\ -L lib\ -shared -o build\scripts\discord-rpc.asi src\discord_rpc.cpp -l discord-rpc

if (!$LastExitCode) {
  # Copy discord-rpc.dll
  Copy-Item "lib\discord-rpc.dll" -Destination "build\"

  # Zip stuff
  Compress-Archive -Force -Path "build\*" -DestinationPath "dist\discord-rpc.zip"

  Write-Output "Built successfully."
  exit
}

Write-Output "Failed to build."
