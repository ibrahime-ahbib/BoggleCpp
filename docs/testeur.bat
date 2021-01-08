@echo off

set exeName=Boggle.exe
set debugDir=..\x64\Debug\
set releaseDir=..\x64\Release\
set inoutDir=inout\

goto main


rem FONCTION err404 - param 1 : le fichier introuvable
:err404
	echo Erreur : le fichier %1 n'existe pas.
	goto VertiableEOF
goto:eof

rem FONCTION tester - param 1 : le numro du sprint
:tester 
	echo - Test du sprint %1 en cours...
	(echo %1 & type "%inoutDir%in%1.txt") | "%debugDir%%exeName%" > tmp\votreOutDebug%1.txt
	(echo %1 & type "%inoutDir%in%1.txt") | "%releaseDir%%exeName%" > tmp\votreOutRelease%1.txt
	
	rem utilisation de fc avec recherche binaire afin de tenir compte des fins de ligne (sans, il ne dtecte pas)
	fc "%inoutDir%out%1.txt" "tmp\votreOutDebug%1.txt" /B > nul
	if errorlevel 1 (
		echo Ouhlala, rien qu'en mode debug, votre out du sprint %1
		echo ne correspond pas au out attendu.
		echo.
		goto:eof
	)
	fc "%inoutDir%out%1.txt" "tmp\votreOutRelease%1.txt" /B > nul
	if errorlevel 1 (
		echo chelou, votre debug %1 marche mais pas le realease !
		echo.
		goto:eof
	)
	echo   ... tout va bien
goto:eof

rem FONCTION ultimeBis - pas d'arguments requis
:ultimeBis
	if exist "%releaseDir%exo.exe" del "%releaseDir%exo.exe"
	echo F | xcopy %releaseDir%%exeName% %releaseDir%exo.exe > nul
	cd ultime
	echo dmarrage de timecmd ultime-bis.bat
	call timecmd ultime-bis.bat
	echo.
	cd ..
goto:eof


rem FONCTION main
:main
	cls
	echo Programme de test projet SDA
	echo par Logan t (https://batch.xoo.it/profile.php?mode=viewprofile^&u=3038)
	echo.
	echo 1. Assurez-vous d'avoir compil votre programme en Debug et Release 
	echo 2. Assurez-vous d'avoir paramtr les variables contenues dans le ce
	echo    fichier et le fichier ultime\ultime-bis.bat
	echo 3. Assurez-vous d'avoir la structure ncessaire au bon fonctionnement
	echo    du programme
	echo.
	pause
	
	if exist tmp rmdir tmp /S /Q
	mkdir tmp

	:: vrif fichiers
	if not exist "%debugDir%%exeName%" goto err404 "%debugDir%%exeName%"
	if not exist "%releaseDir%%exeName%" goto err404 "%releaseDir%%exeName%"

	for /L %%i in (1,1,6) do (
		if not exist "%inoutDir%in%%i.txt" (call :err404 "%inoutDir%in%%i.txt")
		if not exist "%inoutDir%out%%i.txt" (call :err404 "%inoutDir%out%%i.txt")
	)

	echo.
	echo ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
	echo.
	echo Vrification des sprints normaux pour le mode debug ET release
	for /L %%i in (1,1,6) do (call :tester %%i)
	
	echo Vrification normale effectue. Les out sont dans le dossier .\tmp\
	echo.
	echo ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
	echo.
	echo Test de l'ultime en cours ...
	
	call :ultimeBis
	
	echo ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
	echo.
	echo Test termin. Vrifiez bien la correspondance du test ultime avec le
	echo rsultat attendu. ท bient“t !



:VertiableEOF

