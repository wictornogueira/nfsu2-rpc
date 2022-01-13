# Define optional flags
param (
	[switch] $d	  # Generate dist file
)

$baseDir = $pwd
$redistDir = "$pwd\..\redist"
$binDir = "$pwd\bin"
$buildDir = "$binDir\Release"
$tempDir = "$binDir\temp"
$distDir = "$binDir\dist"

# Create dist file
if ($d) {
	# Create temp dir
	New-Item -ItemType Directory -Force -Path "$tempDir\scripts" | Out-Null

	# Copy discord_game_sdk.dll
	Copy-Item -Force "$redistDir\discord_game_sdk.dll" -Destination "$tempDir\"
	# Copy nfsu2-rpc.asi
	Copy-Item -Force "$buildDir\nfsu2-rpc.asi" -Destination "$tempDir\scripts"

	# Create dist dir
	New-Item -ItemType Directory -Force -Path "$distDir\" | Out-Null
	# Zip files
	Compress-Archive -Force -Path "$tempDir\*" -DestinationPath "$distDir\nfsu2-rpc.zip"

	# Delete temp dir
	Remove-Item -Force -Recurse -Path "$tempDir"
}
