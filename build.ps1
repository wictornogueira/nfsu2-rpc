# Create directories
New-Item -ItemType Directory -Force -Path "build\scripts" | Out-Null
New-Item -ItemType Directory -Force -Path "dist\" | Out-Null

# Compile
& i686-w64-mingw32-g++.exe -static-libgcc -mthreads -I src\ -I include\ -L lib\ -l discord-rpc -shared -o build\scripts\nfsu2-rpc.asi src\discord_rpc.cpp

if (!$LastExitCode) {
  # Copy discord-rpc.dll
  Copy-Item "lib\discord-rpc.dll" -Destination "build\"

  # Zip stuff
  Compress-Archive -Force -Path "build\*" -DestinationPath "dist\nfsu2-rpc.zip"

  Write-Output "Built successfully."
  exit
}

Write-Output "Failed to build."
