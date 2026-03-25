CreateObject("WScript.Shell").Run "cmd /c cd /d """ & CreateObject("Scripting.FileSystemObject").GetParentFolderName(WScript.CurrentScript.FullName) & """ && start ui.html", 0, False
