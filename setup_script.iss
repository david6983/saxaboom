[Setup]
AppName=SAXABOOM
AppVersion=1.0.0
DefaultDirName={commoncf}
DefaultGroupName=SAXABOOM
OutputBaseFilename=SAXABOOM-x86-1.0.0-vst3
[Files]
Source: "Builds\VisualStudio2017\x64\Release\VST3\SAXABOOM.vst3"; DestDir: "{app}"
Source: "Samples\sbLoop.wav"; DestDir: "{userdocs}\Saxaboom\Samples"
Source: "Samples\sbLoop1.wav"; DestDir: "{userdocs}\Saxaboom\Samples"
Source: "Samples\sbLoop2.wav"; DestDir: "{userdocs}\Saxaboom\Samples"
Source: "Samples\sbLoop3.wav"; DestDir: "{userdocs}\Saxaboom\Samples"
Source: "Samples\sbLoop4.wav"; DestDir: "{userdocs}\Saxaboom\Samples"
Source: "Samples\sbLoop5.wav"; DestDir: "{userdocs}\Saxaboom\Samples"
Source: "Samples\sbLoop6.wav"; DestDir: "{userdocs}\Saxaboom\Samples"
Source: "Samples\sbLoop8.wav"; DestDir: "{userdocs}\Saxaboom\Samples"
[UninstallDelete]
Type: filesandordirs; Name: "{userdocs}\Saxaboom"