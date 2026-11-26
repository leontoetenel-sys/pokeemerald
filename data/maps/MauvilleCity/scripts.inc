MauvilleCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_OnTransition
	.byte 0

MauvilleCity_OnTransition:
	setflag FLAG_VISITED_MAUVILLE_CITY
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	clearflag FLAG_HIDE_SLATEPORT_MUSEUM_POPULATION
	setflag FLAG_SYS_TV_START
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	setvar VAR_MAUVILLE_GYM_STATE, 0
	call_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_MoveWattsonBackToGym
	end

MauvilleCity_EventScript_MoveWattsonBackToGym::
	clearflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
	setflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	setflag FLAG_WATTSON_REMATCH_AVAILABLE
	return

MauvilleCity_EventScript_Boy::
	msgbox MauvilleCity_Text_NurseHurtMonBackToHealth, MSGBOX_NPC
	end

MauvilleCity_EventScript_Maniac::
	msgbox MauvilleCity_Text_AllSortsOfPeopleComeThrough, MSGBOX_NPC
	end

MauvilleCity_EventScript_Woman::
	msgbox MauvilleCity_Text_RydelVeryGenerous, MSGBOX_NPC
	end

MauvilleCity_EventScript_RichBoy::
	msgbox MauvilleCity_Text_PokemonCanJumpYouOnBike, MSGBOX_NPC
	end

MauvilleCity_EventScript_CitySign::
	msgbox MauvilleCity_Text_CitySign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GymSign::
	msgbox MauvilleCity_Text_GymSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_BikeShopSign::
	msgbox MauvilleCity_Text_BikeShopSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GameCornerSign::
	msgbox MauvilleCity_Text_GameCornerSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_SchoolKidM::
	lock
	faceplayer
	goto_if_set FLAG_TV_EXPLAINED, MauvilleCity_EventScript_TVExplained
	msgbox MauvilleCity_Text_ExplainTV, MSGBOX_DEFAULT
	setflag FLAG_TV_EXPLAINED
	release
	end

MauvilleCity_EventScript_TVExplained::
	msgbox MauvilleCity_Text_BeenCheckingOutTV, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_UncleAskPlayerToBattleWally
	msgbox MauvilleCity_Text_UncleHesTooPeppy, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_MAUVILLE_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	release
	end

MauvilleCity_EventScript_UncleAskPlayerToBattleWally::
	msgbox MauvilleCity_Text_UncleCanYouBattleWally, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_MAUVILLE_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	release
	end

MauvilleCity_EventScript_Wally::
	lockall
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_WallyRequestBattleAgain
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	msgbox MauvilleCity_Text_WallyWantToChallengeGym, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_UncleYourePushingIt, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_WallyWeCanBeatAnyone, MSGBOX_DEFAULT
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	playse SE_PIN
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_Delay48
	msgbox MauvilleCity_Text_WallyWillYouBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_EventScript_BattleWallyPrompt::
	call_if_eq VAR_RESULT, YES, MauvilleCity_EventScript_BattleWally
	goto_if_eq VAR_RESULT, NO, MauvilleCity_EventScript_DeclineWallyBattle
	closemessage
	switch VAR_FACING
	case DIR_NORTH, MauvilleCity_EventScript_WallyAndUncleExitNorth
	case DIR_EAST, MauvilleCity_EventScript_WallyAndUncleExitEast
	end

MauvilleCity_EventScript_WallyAndUncleExitNorth::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth1
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitNorth1
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth1
	waitmovement 0
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	delay 30
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerFaceUncleNorth
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerNorth
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth2
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth2
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitNorth2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_WallyAndUncleExitEast::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast1
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitEast1
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast1
	waitmovement 0
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	delay 30
	applywaitmovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerEast
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast2
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast2
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitEast2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_DefeatedWally::
	removeobject LOCALID_MAUVILLE_WALLY
	removeobject LOCALID_MAUVILLE_WALLYS_UNCLE
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
	setvar VAR_WALLY_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottApproachPlayerNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottApproachPlayerEast
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	msgbox MauvilleCity_Text_ScottYouDidntHoldBack, MSGBOX_DEFAULT
	closemessage
	addvar VAR_SCOTT_STATE, 1
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottExitEast
	removeobject LOCALID_MAUVILLE_SCOTT
	releaseall
	end

MauvilleCity_EventScript_ScottApproachPlayerNorth::
	addobject LOCALID_MAUVILLE_SCOTT
	applywaitmovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottApproachPlayerNorth
	return

MauvilleCity_EventScript_ScottApproachPlayerEast::
	setobjectxyperm LOCALID_MAUVILLE_SCOTT, 12, 13
	addobject LOCALID_MAUVILLE_SCOTT
	applywaitmovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottApproachPlayerEast
	return

MauvilleCity_EventScript_ScottExitNorth::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitNorth
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottExitNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitEast::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitEast
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottExitEast
	waitmovement 0
	return

MauvilleCity_EventScript_BattleWally::
	msgbox MauvilleCity_Text_WallyHereICome, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_MAUVILLE, MauvilleCity_Text_WallyDefeat
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	msgbox MauvilleCity_Text_WallyIllGoBackToVerdanturf, MSGBOX_DEFAULT
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	msgbox MauvilleCity_Text_ThankYouNotEnoughToBattle, MSGBOX_DEFAULT
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	msgbox MauvilleCity_Text_UncleNoNeedToBeDown, MSGBOX_DEFAULT
	return

MauvilleCity_EventScript_DeclineWallyBattle::
	setflag FLAG_DECLINED_WALLY_BATTLE_MAUVILLE
	msgbox MauvilleCity_Text_WallyMyUncleWontKnowImStrong, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallyRequestBattleAgain::
	applywaitmovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	msgbox MauvilleCity_Text_WallyPleaseBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_Movement_WallyExitNorth1:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	step_end

MauvilleCity_Movement_WallyExitEast1:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallyExitNorth2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_WallyExitEast2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast2:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitNorth:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitEast:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast1:
	delay_16
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth1:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_WallysUncleExitNorth1:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

MauvilleCity_Movement_WallysUncleExitEast1:
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_PlayerFaceUncleNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerNorth:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerEast:
	walk_right
	walk_up
	step_end

MauvilleCity_Movement_WallysUncleExitNorth2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallysUncleExitEast2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_ScottApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

MauvilleCity_Movement_ScottExitNorth:
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

MauvilleCity_Movement_ScottExitEast:
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

MauvilleCity_EventScript_Wattson::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_ReceivedThunderbolt
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_EventScript_CompletedNewMauville
	goto_if_set FLAG_GOT_BASEMENT_KEY_FROM_WATTSON, MauvilleCity_EventScript_BegunNewMauville
	msgbox MauvilleCity_Text_WattsonNeedFavorTakeKey, MSGBOX_DEFAULT
	giveitem ITEM_BASEMENT_KEY
	setflag FLAG_GOT_BASEMENT_KEY_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_BegunNewMauville::
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Text_WattsonThanksTakeTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_THUNDERBOLT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_ReceivedThunderbolt::
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_RegisterWallyCall::
	lockall
	pokenavcall MauvilleCity_Text_WallyPokenavCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Text_RegisteredWally, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WALLY_MATCH_CALL
	clearflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	releaseall
	end

MauvilleCity_Text_UncleHesTooPeppy:
	.string "OOM: Door Pokémon heeft hij\n"
	.string "veel meer energie gekregen.\p"
	.string "Maar nu misschien iets te veel...$"

MauvilleCity_Text_WallyWantToChallengeGym:
	.string "WALLY: Ach, oom, alsjeblieft!\p"
	.string "Ik wil deze GYM uitdagen\n"
	.string "om te zien hoe sterk ik ben.\p"
	.string "Mag het? Alsjeblieft?$"

MauvilleCity_Text_UncleYourePushingIt:
	.string "OOM: Wacht even, WALLY.\p"
	.string "Sinds je Pokémon hebt,\n"
	.string "ben je veel sterker geworden.\p"
	.string "Maar is een GYM uitdagen\n"
	.string "niet wat te hoog gegrepen?$"

MauvilleCity_Text_WallyWeCanBeatAnyone:
	.string "WALLY: Helemaal niet!\p"
	.string "Samen met RALTS kan ik\n"
	.string "iedereen verslaan!$"

MauvilleCity_Text_WallyWillYouBattleMe:
	.string "WALLY: O! Hoi, {PLAYER}!\p"
	.string "Ik ben veel sterker geworden\n"
	.string "sinds we elkaar zagen.\p"
	.string "Dat wil ik jou en mijn oom\n"
	.string "graag laten zien.\p"
	.string "Wil je alsjeblieft met me vechten?$"

MauvilleCity_Text_WallyMyUncleWontKnowImStrong:
	.string "WALLY: O... Als je niet met\n"
	.string "me vecht, weet mijn oom niet\l"
	.string "hoe sterk ik ben geworden.$"

MauvilleCity_Text_UncleCanYouBattleWally:
	.string "OOM: {PLAYER}, toch?\p"
	.string "Wil je alsjeblieft een keertje\n"
	.string "met WALLY vechten?\p"
	.string "Volgens mij luistert hij\n"
	.string "nu toch niet naar me.$"

MauvilleCity_Text_WallyPleaseBattleMe:
	.string "WALLY: {PLAYER}, alsjeblieft!\n"
	.string "Vecht met me!$"

MauvilleCity_Text_WallyHereICome:
	.string "WALLY: Bedankt, {PLAYER}.\p"
	.string "Goed... Daar kom ik!$"

MauvilleCity_Text_WallyDefeat:
	.string "WALLY: ... ... ... ...\p"
	.string "Ik heb verloren...$"

MauvilleCity_Text_WallyIllGoBackToVerdanturf:
	.string "WALLY: Oom...\n"
	.string "Ik ga terug naar VERDANTURF...$"

MauvilleCity_Text_ThankYouNotEnoughToBattle:
	.string "Bedankt, {PLAYER}.\n"
	.string "Trainer zijn is lastig, hè?\p"
	.string "Alleen Pokémon hebben en\n"
	.string "vechten is niet genoeg.\p"
	.string "Daar gaat het niet alleen om.$"

MauvilleCity_Text_UncleNoNeedToBeDown:
	.string "OOM: WALLY, wees niet zo\n"
	.string "teleurgesteld in jezelf.\p"
	.string "Je kunt toch steeds sterker\n"
	.string "worden?\p"
	.string "Kom, we gaan naar huis.\n"
	.string "Iedereen wacht op je.$"

MauvilleCity_Text_UncleVisitUsSometime:
	.string "OOM: {PLAYER}, jij bent vast\n"
	.string "de trainer die WALLY hielp\l"
	.string "zijn Pokémon te vangen!\p"
	.string "Kom eens langs in VERDANTURF.\n"
	.string "WALLY zal dat leuk vinden.$"


MauvilleCity_Text_WallyPokenavCall:
	.string "... ... ... ... Piep!\p"
	.string "WALLY: Hoi, {PLAYER}!\p"
	.string "Mijn oom heeft een POKéNAV\n"
	.string "voor me gekocht!\p"
	.string "Nu kan ik je altijd bellen!\p"
	.string "... ... ... ... Klik!$"

MauvilleCity_Text_RegisteredWally:
	.string "WALLY is geregistreerd\n"
	.string "in de POKéNAV.$"

MauvilleCity_Text_ScottYouDidntHoldBack:
	.string "SCOTT: Hihi...\n"
	.string "Ik zag dat duel!\p"
	.string "Jij bent bevriend met WALLY, hè?\p"
	.string "Toch gaf je alles en won je\n"
	.string "op indrukwekkende wijze.\p"
	.string "Daar gaat een echt Pokémon-duel\n"
	.string "om!\p"
	.string "Ik bewonder zulke trainers!\p"
	.string "Ik zal voor je juichen!$"

MauvilleCity_Text_WattsonNeedFavorTakeKey:
	.string "WATTSON: O, {PLAYER}!\n"
	.string "Wat heb jij veel energie!\p"
	.string "Wahahahaha! Dat is mooi!\p"
	.string "Ik heb besloten dat ik je\n"
	.string "om een gunst ga vragen.\p"
	.string "Onder MAUVILLE CITY ligt\n"
	.string "NEW MAUVILLE.\p"
	.string "Wil je daar de GENERATOR\n"
	.string "uitzetten?\p"
	.string "Hij doet een beetje vreemd.\n"
	.string "Het wordt gevaarlijk.\p"
	.string "Hier is de KEY waarmee je\n"
	.string "NEW MAUVILLE binnenkomt.$"

MauvilleCity_Text_WattsonWontBeChallenge:
	.string "WATTSON: Maak je geen zorgen.\n"
	.string "Dit lukt jou wel!\p"
	.string "Vanaf ROUTE 110 kun je met\n"
	.string "SURF naar de ingang.\p"
	.string "Ik vertrouw op je!\n"
	.string "Wahahahaha!$"

MauvilleCity_Text_WattsonThanksTakeTM:
	.string "WATTSON: Wahahahaha!\p"
	.string "Ik wist dat jij de juiste\n"
	.string "persoon was, {PLAYER}!\p"
	.string "Als dank krijg je een TM\n"
	.string "met THUNDERBOLT!\p"
	.string "Je hebt hem verdiend!$"

MauvilleCity_Text_WattsonYoungTakeCharge:
	.string "WATTSON: Wahahahaha!\p"
	.string "Wat fijn om te zien dat jonge\n"
	.string "trainers het voortouw nemen!$"

MauvilleCity_Text_NurseHurtMonBackToHealth:
	.string "Pokémon-duels zijn leuk...\p"
	.string "Maar als je Pokémon gewond is,\n"
	.string "moet je goed voor hem zorgen.$"

MauvilleCity_Text_AllSortsOfPeopleComeThrough:
	.string "De wegen lopen naar het noorden,\n"
	.string "zuiden, oosten en westen.\p"
	.string "Daarom komen hier allerlei\n"
	.string "verschillende mensen langs.$"

MauvilleCity_Text_RydelVeryGenerous:
	.string "Ben je al bij RYDEL'S CYCLES\n"
	.string "geweest?\p"
	.string "RYDEL is een heel gulle man.$"

MauvilleCity_Text_PokemonCanJumpYouOnBike:
	.string "Ook als je fietst, kunnen\n"
	.string "wilde Pokémon je aanvallen.$"

MauvilleCity_Text_CitySign:
	.string "MAUVILLE CITY\n"
	.string "De stralende stad vol plezier!$"

MauvilleCity_Text_GymSign:
	.string "MAUVILLE CITY POKéMON GYM\n"
	.string "LEADER: WATTSON\l"
	.string "Een man vol vrolijke energie!$"

MauvilleCity_Text_BikeShopSign:
	.string "Voel de wind tijdens het fietsen!\n"
	.string "RYDEL'S CYCLES$"

MauvilleCity_Text_GameCornerSign:
	.string "Een speelplek voor iedereen!\n"
	.string "MAUVILLE GAME CORNER$"

MauvilleCity_Text_ExplainTV:
	.string "Hoi, kijk jij wel eens tv?\p"
	.string "Er zijn allerlei leuke nieuwe\n"
	.string "programma's bij gekomen.\p"
	.string "Ik heb zomaar vrienden\n"
	.string "op tv gezien!\p"
	.string "Soms kom je zelfs op tv\n"
	.string "zonder dat je het weet.\p"
	.string "Ik wil ook wel eens op tv!\p"
	.string "Kijk dus af en toe naar\n"
	.string "een televisie.$"

MauvilleCity_Text_BeenCheckingOutTV:
	.string "Hoi, heb je al tv gekeken?$"
