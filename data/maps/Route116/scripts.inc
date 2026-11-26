Route116_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route116_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route116_OnFrame
	.byte 0

Route116_OnTransition:
	call_if_set FLAG_RECOVERED_DEVON_GOODS, Route116_EventScript_SetWandasBoyfriendPos
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_NORTH, AbnormalWeather_StartGroudonWeather
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_SOUTH, AbnormalWeather_StartGroudonWeather
	end

Route116_EventScript_SetWandasBoyfriendPos::
	setobjectxyperm LOCALID_ROUTE116_WANDAS_BF, 38, 10
	return

Route116_OnLoad:
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_NORTH, AbnormalWeather_EventScript_PlaceTilesRoute116North
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_SOUTH, AbnormalWeather_EventScript_PlaceTilesRoute116South
	end

Route116_OnFrame:
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route116_EventScript_WandasBoyfriend::
	lock
	faceplayer
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, Route116_EventScript_BoyfriendGruntLeftTunnel
	goto_if_set FLAG_DEVON_GOODS_STOLEN, Route116_EventScript_BoyfriendGruntInTunnel
	msgbox Route116_Text_WantToDigTunnel, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_BoyfriendGruntLeftTunnel::
	msgbox Route116_Text_GoonHightailedItOutOfTunnel, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_BoyfriendGruntInTunnel::
	msgbox Route116_Text_DiggingTunnelWhenGoonOrderedMeOut, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_DevonEmployee::
	lock
	faceplayer
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, Route116_EventScript_TryGiveRepeatBallAgain
	msgbox Route116_Text_ThankYouTokenOfAppreciation, MSGBOX_DEFAULT
	goto Route116_EventScript_GiveRepeatBall
	end

Route116_EventScript_GiveRepeatBall::
	setflag FLAG_MET_DEVON_EMPLOYEE
	giveitem ITEM_REPEAT_BALL
	goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_NoRoomForRepeatBall
	msgbox Route116_Text_NewBallAvailableAtMart, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, Route116_EventScript_DevonEmployeeExit
	call_if_eq VAR_FACING, DIR_SOUTH, Route116_EventScript_DevonEmployeeExit
	call_if_eq VAR_FACING, DIR_WEST, Route116_EventScript_DevonEmployeeExit
	call_if_eq VAR_FACING, DIR_EAST, Route116_EventScript_DevonEmployeeExitEast
	removeobject VAR_LAST_TALKED
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
	setflag FLAG_RECEIVED_REPEAT_BALL
	release
	end

Route116_EventScript_DevonEmployeeExit::
	applywaitmovement VAR_LAST_TALKED, Route116_Movement_DevonEmployeeExit
	return

Route116_EventScript_DevonEmployeeExitEast::
	applywaitmovement VAR_LAST_TALKED, Route116_Movement_DevonEmployeeExitEast
	return

Route116_EventScript_TryGiveRepeatBallAgain::
	msgbox Route116_Text_TokenOfAppreciation, MSGBOX_DEFAULT
	goto Route116_EventScript_GiveRepeatBall
	end

Route116_EventScript_NoRoomForRepeatBall::
	msgbox Route116_Text_BagIsJamPacked, MSGBOX_DEFAULT
	release
	end

Route116_Movement_DevonEmployeeExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route116_Movement_DevonEmployeeExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route116_EventScript_RouteSignRustboro::
	msgbox Route116_Text_RouteSignRustboro, MSGBOX_SIGN
	end

Route116_EventScript_RusturfTunnelSign::
	msgbox Route116_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

Route116_EventScript_TunnelersRestHouseSign::
	msgbox Route116_Text_TunnelersRestHouse, MSGBOX_SIGN
	end

Route116_EventScript_TrainerTipsBToStopEvolution::
	msgbox Route116_Text_TrainerTipsBToStopEvolution, MSGBOX_SIGN
	end

Route116_EventScript_TrainerTipsBagHasPockets::
	msgbox Route116_Text_TrainerTipsBagHasPockets, MSGBOX_SIGN
	end

Route116_EventScript_Briney::
	lock
	faceplayer
	msgbox Route116_Text_ScoundrelMadeOffWithPeeko, MSGBOX_DEFAULT
	setvar VAR_ROUTE116_STATE, 2
	release
	end

Route116_EventScript_BrineyTrigger::
	lockall
	applymovement LOCALID_ROUTE116_BRINEY, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox Route116_Text_ScoundrelMadeOffWithPeeko, MSGBOX_DEFAULT
	setvar VAR_ROUTE116_STATE, 2
	releaseall
	end

Route116_EventScript_GlassesMan::
	lock
	faceplayer
	checkitem ITEM_BLACK_GLASSES
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_PlayerHasGlasses
	specialvar VAR_RESULT, FoundBlackGlasses
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_FoundGlassesNotOnPlayer
	msgbox Route116_Text_CanYouHelpMeFindGlasses, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_FoundGlassesNotOnPlayer::
	msgbox Route116_Text_CantFindGlassesNotHere, MSGBOX_DEFAULT
	closemessage
	goto Route116_EventScript_GlassesManExit
	end

Route116_EventScript_PlayerHasGlasses::
	msgbox Route116_Text_CanYouHelpMeFindGlasses, MSGBOX_DEFAULT
	msgbox Route116_Text_MayISeeThoseGlasses, MSGBOX_DEFAULT
	specialvar VAR_RESULT, FoundBlackGlasses
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_FoundGlassesOnPlayer
	msgbox Route116_Text_NotWhatImLookingFor, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_FoundGlassesOnPlayer::
	msgbox Route116_Text_NotWhatImLookingForMaybeTheyArentHere, MSGBOX_DEFAULT
	closemessage
	goto Route116_EventScript_GlassesManExit
	end

Route116_EventScript_GlassesManExit::
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, Route116_EventScript_GlassesManExitNormal
	call_if_eq VAR_FACING, DIR_SOUTH, Route116_EventScript_GlassesManExitNormal
	call_if_eq VAR_FACING, DIR_WEST, Route116_EventScript_GlassesManExitNormal
	call_if_eq VAR_FACING, DIR_EAST, Route116_EventScript_GlassesManExitEast
	removeobject VAR_LAST_TALKED
	release
	end

Route116_EventScript_GlassesManExitNormal::
	applywaitmovement VAR_LAST_TALKED, Route116_Movement_GlassesManExit
	return

Route116_EventScript_GlassesManExitEast::
	applywaitmovement VAR_LAST_TALKED, Route116_Movement_GlassesManExitEast
	return

Route116_Movement_GlassesManExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route116_Movement_GlassesManExitEast:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route116_EventScript_Joey::
	trainerbattle_single TRAINER_JOEY, Route116_Text_JoeyIntro, Route116_Text_JoeyDefeat
	msgbox Route116_Text_JoeyPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Jose::
	trainerbattle_single TRAINER_JOSE, Route116_Text_JoseIntro, Route116_Text_JoseDefeat
	msgbox Route116_Text_JosePostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Jerry::
	trainerbattle_single TRAINER_JERRY_1, Route116_Text_JerryIntro, Route116_Text_JerryDefeat, Route116_EventScript_TryRegisterJerryAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_RematchJerry
	setvar VAR_0x8004, TRAINER_JERRY_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_TryRegisterJerry
	msgbox Route116_Text_JerryPostBattle, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_TryRegisterJerryAfterBattle::
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterJerryAfterBattle
	release
	end

Route116_EventScript_RegisterJerryAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route116_Text_JerryRegister2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JERRY_1
	release
	end

Route116_EventScript_TryRegisterJerry::
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterJerry
	msgbox Route116_Text_JerryPostBattle, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_RegisterJerry::
	msgbox Route116_Text_JerryRegister1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JERRY_1
	release
	end

Route116_EventScript_RematchJerry::
	trainerbattle_rematch TRAINER_JERRY_1, Route116_Text_JerryRematchIntro, Route116_Text_JerryRematchDefeat
	msgbox Route116_Text_JerryPostRematch, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Clark::
	trainerbattle_single TRAINER_CLARK, Route116_Text_ClarkIntro, Route116_Text_ClarkDefeat
	msgbox Route116_Text_ClarkPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Janice::
	trainerbattle_single TRAINER_JANICE, Route116_Text_JaniceIntro, Route116_Text_JaniceDefeat
	msgbox Route116_Text_JanicePostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Karen::
	trainerbattle_single TRAINER_KAREN_1, Route116_Text_KarenIntro, Route116_Text_KarenDefeat, Route116_EventScript_TryRegisterKarenAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_RematchKaren
	setvar VAR_0x8004, TRAINER_KAREN_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_TryRegisterKaren
	msgbox Route116_Text_KarenPostBattle, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_TryRegisterKarenAfterBattle::
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterKarenAfterBattle
	release
	end

Route116_EventScript_RegisterKarenAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route116_Text_KarenRegister2, MSGBOX_DEFAULT
	register_matchcall TRAINER_KAREN_1
	release
	end

Route116_EventScript_TryRegisterKaren::
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterKaren
	msgbox Route116_Text_KarenPostBattle, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_RegisterKaren::
	msgbox Route116_Text_KarenRegister1, MSGBOX_DEFAULT
	register_matchcall TRAINER_KAREN_1
	release
	end

Route116_EventScript_RematchKaren::
	trainerbattle_rematch TRAINER_KAREN_1, Route116_Text_KarenRematchIntro, Route116_Text_KarenRematchDefeat
	msgbox Route116_Text_KarenPostRematch, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Sarah::
	trainerbattle_single TRAINER_SARAH, Route116_Text_SarahIntro, Route116_Text_SarahDefeat
	msgbox Route116_Text_SarahPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Dawson::
	trainerbattle_single TRAINER_DAWSON, Route116_Text_DawsonIntro, Route116_Text_DawsonDefeat
	msgbox Route116_Text_DawsonPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Devan::
	trainerbattle_single TRAINER_DEVAN, Route116_Text_DevanIntro, Route116_Text_DevanDefeat
	msgbox Route116_Text_DevanPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Johnson::
	trainerbattle_single TRAINER_JOHNSON, Route116_Text_JohnsonIntro, Route116_Text_JohnsonDefeat
	msgbox Route116_Text_JohnsonPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_Text_ScoundrelMadeOffWithPeeko:
	.string "Ooooh, wat moet ik nu doen?\p"
	.string "PEEKO en ik waren aan het\n"
	.string "wandelen toen een vreemde\l"
	.string "boef ons overviel.\p"
	.string "Die schurk nam mijn lieve\n"
	.string "PEEKO mee!\p"
	.string "Wraaaaaah! PEEKO!$"

Route116_Text_WantToDigTunnel:
	.string "Grrr... Aaargh!\p"
	.string "Ik wil die tunnel graven!$"

Route116_Text_DiggingTunnelWhenGoonOrderedMeOut:
	.string "Grrr... Aaargh!\n"
	.string "Wat gebeurt hier toch?\p"
	.string "Ik groef de tunnel zonder\n"
	.string "gereedschap toen een boef\l"
	.string "me naar buiten stuurde!\p"
	.string "In die tunnel leven Pokémon\n"
	.string "die niet tegen harde geluiden\l"
	.string "kunnen. Ze raken dan in paniek.\p"
	.string "Daarom gebruiken we geen\n"
	.string "zware machines meer...\p"
	.string "Ik ben bang dat die boef iets\n"
	.string "stoms doet en de Pokémon\l"
	.string "laat schrikken.$"

Route116_Text_GoonHightailedItOutOfTunnel:
	.string "Grrr... Aaargh!\p"
	.string "Die gekke boef is de tunnel\n"
	.string "uit gevlucht!\p"
	.string "Ik kan weer verder graven!$"

Route116_Text_ThankYouTokenOfAppreciation:
	.string "O! Jij bent het!\p"
	.string "Je hielp me in PETALBURG WOODS,\n"
	.string "haalde mijn gestolen pakje terug\l"
	.string "en bracht het zelfs naar SLATEPORT!\p"
	.string "CAPT. STERN heeft ons verteld\n"
	.string "dat het pakje is aangekomen.\p"
	.string "Heel erg bedankt!\p"
	.string "Als ik een regenwolk was, zou\n"
	.string "ik je overspoelen met dank!\p"
	.string "Voor zo'n geweldige trainer\n"
	.string "heb ik goed nieuws!\p"
	.string "Ons bedrijf heeft onlangs een\n"
	.string "nieuw soort Poké Ball gemaakt.\p"
	.string "Als bedankje krijg je er\n"
	.string "eentje van ons!$"

Route116_Text_NewBallAvailableAtMart:
	.string "Onze nieuwe Poké Ball is straks\n"
	.string "te koop in de Pokémon MART\l"
	.string "van RUSTBORO.\p"
	.string "Probeer hem eens!\n"
	.string "Bedankt en tot ziens!$"

Route116_Text_BagIsJamPacked:
	.string "Je BAG zit helemaal vol.\n"
	.string "Ik kan je deze REPEAT BALL\l"
	.string "niet geven.$"

Route116_Text_TokenOfAppreciation:
	.string "Als dank voor het bezorgen\n"
	.string "van ons pakje heb ik een\l"
	.string "nieuwe Poké Ball voor je!$"

Route116_Text_CanYouHelpMeFindGlasses:
	.string "Ik heb mijn bril laten vallen...\n"
	.string "Wil je me helpen zoeken?$"

Route116_Text_MayISeeThoseGlasses:
	.string "Die bril!\n"
	.string "Mag ik hem even bekijken?$"

Route116_Text_NotWhatImLookingForMaybeTheyArentHere:
	.string "Hmm...\n"
	.string "Dit is een BLACKGLASSES.\l"
	.string "Die zoek ik niet...\p"
	.string "Misschien ligt mijn bril\n"
	.string "hier helemaal niet.$"

Route116_Text_CantFindGlassesNotHere:
	.string "Hmm...\n"
	.string "Ik kan mijn bril nergens vinden.\p"
	.string "Misschien ligt hij hier niet...$"

Route116_Text_NotWhatImLookingFor:
	.string "Hmm...\n"
	.string "Dit is een BLACKGLASSES.\l"
	.string "Die zoek ik niet...$"

Route116_Text_RouteSignRustboro:
	.string "ROUTE 116\n"
	.string "{LEFT_ARROW} RUSTBORO CITY$"

Route116_Text_RusturfTunnelSign:
	.string "RUSTURF TUNNEL\n"
	.string "Verbindt RUSTBORO en VERDANTURF.\p"
	.string "De bouw van de tunnel is gestopt.$"

Route116_Text_TunnelersRestHouse:
	.string "RUSTHUIS VOOR TUNNELBOUWERS$"

Route116_Text_TrainerTipsBToStopEvolution:
	.string "TRAINERTIPS\p"
	.string "Wil je voorkomen dat een\n"
	.string "Pokémon evolueert?\p"
	.string "Druk op B tijdens de evolutie.\n"
	.string "De Pokémon schrikt en stopt.\p"
	.string "Zo kun je een evolutie afbreken.$"

Route116_Text_TrainerTipsBagHasPockets:
	.string "TRAINERTIPS\p"
	.string "Je BAG heeft meerdere vakken.\p"
	.string "Voorwerpen die je krijgt,\n"
	.string "komen vanzelf in het juiste vak.\p"
	.string "Elke trainer heeft een eigen\n"
	.string "BAG nodig.$"

