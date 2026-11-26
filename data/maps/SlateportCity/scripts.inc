SlateportCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_OnFrame
	.byte 0

SlateportCity_OnTransition:
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
	call SlateportCity_EventScript_EnterSlateport
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_MovePeopleForSternInterview
	call_if_eq VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_SetReadyForScottScene
	end

SlateportCity_EventScript_EnterSlateport::
	setflag FLAG_VISITED_SLATEPORT_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
	return

SlateportCity_EventScript_MovePeopleForSternInterview::
	setobjectxyperm LOCALID_SLATEPORT_CAPT_STERN, 28, 13
	setobjectxyperm LOCALID_SLATEPORT_OLD_WOMAN, 25, 13
	setobjectxyperm LOCALID_SLATEPORT_RICH_BOY, 25, 14
	setobjectxyperm LOCALID_SLATEPORT_COOK, 27, 16
	setobjectxyperm LOCALID_SLATEPORT_GIRL, 28, 16
	setobjectxyperm LOCALID_SLATEPORT_FAT_MAN, 29, 16
	setobjectxyperm LOCALID_SLATEPORT_MAN_1, 31, 14
	setobjectmovementtype LOCALID_SLATEPORT_CAPT_STERN, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_SLATEPORT_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	setobjectmovementtype LOCALID_SLATEPORT_RICH_BOY, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
	setobjectmovementtype LOCALID_SLATEPORT_COOK, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_GIRL, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_FAT_MAN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_MAN_1, MOVEMENT_TYPE_FACE_LEFT
	return

SlateportCity_EventScript_SetReadyForScottScene::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 30, SlateportCity_EventScript_MoveScottLeft
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 23, 27
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_EventScript_MoveScottLeft::
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 22, 27
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_OnFrame:
	map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_ScottScene
	.2byte 0

SlateportCity_EventScript_ScottScene::
	lockall
	addobject LOCALID_SLATEPORT_SCOTT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceScott
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottApproachPlayer
	waitmovement 0
	msgbox SlateportCity_Text_YouDroveTeamAquaAway, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	delay 60
	msgbox SlateportCity_Text_MaybeThisTrainer, MSGBOX_DEFAULT
	applywaitmovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterRight
	msgbox SlateportCity_Text_LetsRegisterEachOther, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SlateportCity_Text_RegisteredScott, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_SCOTT_MATCH_CALL
	msgbox SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExit
	removeobject LOCALID_SLATEPORT_SCOTT
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 10, 12
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_DOWN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

SlateportCity_Movement_PlayerFaceScott:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ScottApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_Movement_ScottExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_EventScript_EnergyGuru::
	lock
	faceplayer
	message SlateportCity_Text_EnergyGuruSellWhatYouNeed
	waitmessage
	pokemart SlateportCity_Pokemart_EnergyGuru
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_EnergyGuru:
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_ZINC
	.2byte ITEM_CALCIUM
	.2byte ITEM_HP_UP
	pokemartlistend

SlateportCity_EventScript_EffortRibbonWoman::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox SlateportCity_Text_OhYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
	call_if_eq VAR_RESULT, TRUE, SlateportCity_EventScript_MonHasEffortRibbon
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
	call_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_MonEVsNotMaxed
	msgbox SlateportCity_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message SlateportCity_Text_ReceivedEffortRibbon
	waitfanfare
	msgbox SlateportCity_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
	special GiveLeadMonEffortRibbon
	release
	end

SlateportCity_EventScript_MonEVsNotMaxed::
	msgbox SlateportCity_Text_GoForItLittleHarder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_MonHasEffortRibbon::
	msgbox SlateportCity_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Cook::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_CookSternInterview
	msgbox SlateportCity_Text_SeaweedFullOfLife, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_CookSternInterview::
	msgbox SlateportCity_Text_CaptainComeBackWithBigFish, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWoman::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_OldWomanSternInterview
	msgbox SlateportCity_Text_HowTownIsBornAndGrows, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWomanSternInterview::
	msgbox SlateportCity_Text_CaptSternBeingInterviewed, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Girl::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_GirlSternInterview
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_GirlSecretBase
	msgbox SlateportCity_Text_SlateportWonderfulPlace, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSternInterview::
	msgbox SlateportCity_Text_InterviewerSoCool, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSecretBase::
	msgbox SlateportCity_Text_BuyBricksSoDecorWontGetDirty, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoy::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_RichBoySternInterview
	msgbox SlateportCity_Text_GoingToCompeteInBattleTent, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoySternInterview::
	msgbox SlateportCity_Text_SternSaysDiscoveredSomething, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_FatMan::
	goto_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_FatManSternInterview
	msgbox SlateportCity_Text_BushedHikingFromMauville, MSGBOX_NPC
	end

SlateportCity_EventScript_FatManSternInterview::
	msgbox SlateportCity_Text_AmIOnTV, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man1::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_Man1SternInterview
	msgbox SlateportCity_Text_EveryoneCallsHimCaptStern, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Man1SternInterview::
	msgbox SlateportCity_Text_CaptainsACelebrity, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1::
	lock
	faceplayer
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_EventScript_Woman1AquaGone
	msgbox SlateportCity_Text_WhatsLongLineOverThere, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1AquaGone::
	msgbox SlateportCity_Text_VisitedMuseumOften, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_BattleTentSign::
	msgbox SlateportCity_Text_BattleTentSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_SternsShipyardSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_SternsShipyardFerryComplete
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_SternsShipyardNearsCompletion
	msgbox SlateportCity_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardNearsCompletion::
	msgbox SlateportCity_Text_SternsShipyardNearsCompletion, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardFerryComplete::
	msgbox SlateportCity_Text_SternsShipyardFerryComplete, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_PokemonFanClubSign::
	msgbox SlateportCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_OceanicMuseumSign::
	msgbox SlateportCity_Text_OceanicMuseumSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_CitySign::
	msgbox SlateportCity_Text_CitySign, MSGBOX_SIGN
	end

SlateportCity_EventScript_MarketSign::
	msgbox SlateportCity_Text_MarketSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_HarborSignFerryComplete
	msgbox SlateportCity_Text_HarborFerryUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_HarborSignFerryComplete::
	msgbox SlateportCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_NameRatersHouseSign::
	msgbox SlateportCity_Text_NameRatersHouseSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_Maniac::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_ManiacSternInterview
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

@ Unclear if the text here was meant to be different, but its not
SlateportCity_EventScript_ManiacSternInterview::
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman2::
	msgbox SlateportCity_Text_CantChangeTradeMonName, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor1::
	msgbox SlateportCity_Text_SeaIsSoWet, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor2::
	msgbox SlateportCity_Text_SinkOldBoats, MSGBOX_NPC
	end

SlateportCity_EventScript_PokefanF::
	msgbox SlateportCity_Text_BuyTooMuch, MSGBOX_NPC
	end

SlateportCity_EventScript_Man2::
	msgbox SlateportCity_Text_BattleTentBuiltRecently, MSGBOX_NPC
	end

SlateportCity_EventScript_AquaGrunt1::
	lock
	faceplayer
	msgbox SlateportCity_Text_QuitPushing, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GRUNT_1, Common_Movement_FaceOriginalDirection
	release
	end

SlateportCity_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox SlateportCity_Text_AquaHasPolicy, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GRUNT_2, Common_Movement_FaceOriginalDirection
	release
	end

SlateportCity_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox SlateportCity_Text_BossIsBrilliant, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GRUNT_3, Common_Movement_FaceOriginalDirection
	release
	end

SlateportCity_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhatsNewSchemeIWonder, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GRUNT_4, Common_Movement_FaceOriginalDirection
	release
	end

SlateportCity_EventScript_AquaGrunt5::
	lock
	faceplayer
	msgbox SlateportCity_Text_ShouldTakeItAll, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GRUNT_5, Common_Movement_FaceOriginalDirection
	release
	end

SlateportCity_EventScript_AquaGrunt6::
	lock
	faceplayer
	msgbox SlateportCity_Text_DontButtIn, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GRUNT_6, Common_Movement_FaceOriginalDirection
	release
	end

SlateportCity_EventScript_AquaGrunt7::
	lock
	faceplayer
	msgbox SlateportCity_Text_RemindsMeOfLongLineForGames, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GRUNT_7, Common_Movement_FaceOriginalDirection
	release
	end

SlateportCity_EventScript_AquaGrunt8::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhyAreWeLiningUp, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GRUNT_8, Common_Movement_FaceOriginalDirection
	release
	end

SlateportCity_EventScript_AquaGrunt9::
	lock
	faceplayer
	playse SE_PIN
	applywaitmovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_Delay48
	msgbox SlateportCity_Text_WhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	applywaitmovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	applywaitmovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
	msgbox SlateportCity_Text_IllReadSignForYou, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	applywaitmovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	msgbox SlateportCity_Text_SaysSomethingLikeSeaIsEndless, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
	applywaitmovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	applywaitmovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	release
	end

SlateportCity_Movement_DelayAquaGrunt:
	delay_16
	delay_16
	step_end

SlateportCity_EventScript_AquaGrunt10::
	msgbox SlateportCity_Text_ShouldveBroughtMyGameBoy, MSGBOX_SIGN
	end

SlateportCity_EventScript_AquaGrunt11::
	lock
	faceplayer
	msgbox SlateportCity_Text_HotSpringsAfterOperation, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GRUNT_11, Common_Movement_FaceOriginalDirection
	release
	end

SlateportCity_EventScript_DollClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor_Dolls:
	.2byte DECOR_AZURILL_DOLL
	.2byte DECOR_MARILL_DOLL
	.2byte DECOR_SKITTY_DOLL
	pokemartlistend

SlateportCity_EventScript_ComeBackWithSecretPower::
	msgbox gText_ComeBackWithSecretPower, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_DecorClerk::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_ComeBackWithSecretPower
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor:
	.2byte DECOR_RED_BRICK
	.2byte DECOR_BLUE_BRICK
	.2byte DECOR_YELLOW_BRICK
	.2byte DECOR_RED_BALLOON
	.2byte DECOR_BLUE_BALLOON
	.2byte DECOR_YELLOW_BALLOON
	.2byte DECOR_C_LOW_NOTE_MAT
	.2byte DECOR_D_NOTE_MAT
	.2byte DECOR_E_NOTE_MAT
	.2byte DECOR_F_NOTE_MAT
	.2byte DECOR_G_NOTE_MAT
	.2byte DECOR_A_NOTE_MAT
	.2byte DECOR_B_NOTE_MAT
	.2byte DECOR_C_HIGH_NOTE_MAT
	pokemartlistend

SlateportCity_EventScript_PowerTMClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Pokemart_PowerTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_PowerTMs:
	.2byte ITEM_TM_HIDDEN_POWER
	.2byte ITEM_TM_SECRET_POWER
	pokemartlistend

@ Scene with Capt Sterns interview and Team Aqua announcing plans to steal Submarine
SlateportCity_EventScript_CaptStern::
	lockall
	msgbox SlateportCity_Text_SternMoveAheadWithExploration, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_GabbyWonderfulThanksForInterview, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SLATEPORT_GABBY, Common_Movement_WalkInPlaceFasterRight
	delay 10
	applywaitmovement LOCALID_SLATEPORT_TY, Common_Movement_WalkInPlaceFasterDown
	delay 25
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternWatchGabbyAndTyExit
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceStern
	applymovement LOCALID_SLATEPORT_GABBY, SlateportCity_Movement_GabbyExit
	applymovement LOCALID_SLATEPORT_TY, SlateportCity_Movement_TyExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_GABBY
	removeobject LOCALID_SLATEPORT_TY
	msgbox SlateportCity_Text_SternWhewFirstInterview, MSGBOX_DEFAULT
	applywaitmovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	msgbox SlateportCity_Text_OhPlayerWeMadeDiscovery, MSGBOX_DEFAULT
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SlateportCity_Text_AquaWillAssumeControlOfSubmarine, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_COOK, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SLATEPORT_FAT_MAN, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SLATEPORT_OLD_WOMAN, SlateportCity_Movement_OldWomanConcern
	applymovement LOCALID_SLATEPORT_RICH_BOY, Common_Movement_QuestionMark
	applymovement LOCALID_SLATEPORT_MAN_1, SlateportCity_Movement_ManConcern
	waitmovement 0
	applywaitmovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterDown
	msgbox SlateportCity_Text_SternWhatWasAllThat, MSGBOX_DEFAULT
	playse SE_PIN
	applywaitmovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_Delay48
	applywaitmovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	msgbox SlateportCity_Text_FromHarborTryingToTakeSub, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternEnterHarbor
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerEnterHarbor
	waitmovement 0
	removeobject LOCALID_SLATEPORT_CAPT_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
	setvar VAR_SLATEPORT_CITY_STATE, 2
	warp MAP_SLATEPORT_CITY_HARBOR, 11, 14
	waitstate
	releaseall
	end

SlateportCity_Movement_OldWomanConcern:
	delay_16
	delay_16
	emote_question_mark
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ManConcern:
	emote_question_mark
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_GabbyExit:
	delay_16
	walk_left
	walk_left
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

SlateportCity_Movement_TyExit:
	walk_down
	walk_left
	walk_left
	walk_left
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

SlateportCity_Movement_Unused:
	walk_down
	walk_in_place_faster_up
	step_end

SlateportCity_Movement_SternEnterHarbor:
	walk_right
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_Movement_SternWatchGabbyAndTyExit:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	step_end

SlateportCity_Movement_PlayerEnterHarbor:
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_right
	walk_up
	step_end

SlateportCity_Movement_PlayerFaceStern:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_EventScript_Ty::
	msgbox SlateportCity_Text_BigSmileForCamera, MSGBOX_SIGN
	end

SlateportCity_EventScript_Gabby::
	msgbox SlateportCity_Text_MostInvaluableExperience, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man3::
	msgbox SlateportCity_Text_WonderIfLighthouseStartlesPokemon, MSGBOX_NPC
	end

SlateportCity_EventScript_BerryPowderClerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_ReceivedPowderJar
	msgbox SlateportCity_Text_ExplainBerries, MSGBOX_DEFAULT
	giveitem ITEM_POWDER_JAR
	setflag FLAG_RECEIVED_POWDER_JAR
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ReceivedPowderJar::
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_ExplainBerryPowder
	msgbox SlateportCity_Text_BroughtMeSomeBerryPowder, MSGBOX_DEFAULT
	special DisplayBerryPowderVendorMenu
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ExplainBerryPowder::
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ChooseBerryPowderItem::
	message SlateportCity_Text_ExchangeWhatWithIt
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
	special ShowScrollableMultichoice
	switch VAR_RESULT
	case 0, SlateportCity_EventScript_EnergyPowder
	case 1, SlateportCity_EventScript_EnergyRoot
	case 2, SlateportCity_EventScript_HealPowder
	case 3, SlateportCity_EventScript_RevivalHerb
	case 4, SlateportCity_EventScript_Protein
	case 5, SlateportCity_EventScript_Iron
	case 6, SlateportCity_EventScript_Carbos
	case 7, SlateportCity_EventScript_Calcium
	case 8, SlateportCity_EventScript_Zinc
	case 9, SlateportCity_EventScript_HPUp
	case 10, SlateportCity_EventScript_PPUp
	case 11, SlateportCity_EventScript_CancelPowderItemSelect
	case MULTI_B_PRESSED, SlateportCity_EventScript_CancelPowderItemSelect
	end

SlateportCity_EventScript_EnergyPowder::
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_EnergyRoot::
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
	setvar VAR_0x8009, 80
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HealPowder::
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
	setvar VAR_0x8008, ITEM_HEAL_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_RevivalHerb::
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
	setvar VAR_0x8009, 300
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Protein::
	bufferitemname STR_VAR_1, ITEM_PROTEIN
	setvar VAR_0x8008, ITEM_PROTEIN
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Iron::
	bufferitemname STR_VAR_1, ITEM_IRON
	setvar VAR_0x8008, ITEM_IRON
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Carbos::
	bufferitemname STR_VAR_1, ITEM_CARBOS
	setvar VAR_0x8008, ITEM_CARBOS
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Calcium::
	bufferitemname STR_VAR_1, ITEM_CALCIUM
	setvar VAR_0x8008, ITEM_CALCIUM
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Zinc::
	bufferitemname STR_VAR_1, ITEM_ZINC
	setvar VAR_0x8008, ITEM_ZINC
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HPUp::
	bufferitemname STR_VAR_1, ITEM_HP_UP
	setvar VAR_0x8008, ITEM_HP_UP
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_PPUp::
	bufferitemname STR_VAR_1, ITEM_PP_UP
	setvar VAR_0x8008, ITEM_PP_UP
	setvar VAR_0x8009, 3000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_CancelPowderItemSelect::
	msgbox SlateportCity_Text_ComeBackToTradeBerryPowder, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_TryBuyBerryPowderItem::
	msgbox SlateportCity_Text_ExchangeBerryPowderForItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_ChooseBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NotEnoughBerryPowder
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NoRoomForBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	msgbox SlateportCity_Text_FineBerryPowderTradeSomethingElse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_EventScript_ChooseBerryPowderItem
	msgbox SlateportCity_Text_WhenYouGetMoreBringItToMe, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NoRoomForBerryPowderItem::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NotEnoughBerryPowder::
	msgbox SlateportCity_Text_DontHaveEnoughBerryPowder, MSGBOX_DEFAULT
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ScottBattleTentScene::
	lockall
	applywaitmovement LOCALID_PLAYER, Common_Movement_FaceUp
	opendoor 10, 12
	waitdooranim
	addobject LOCALID_SLATEPORT_SCOTT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PushPlayerDown
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitBattleTent
	waitmovement 0
	closedoor 10, 12
	waitdooranim
	msgbox SlateportCity_Text_TakingBattleTentChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitAfterBattleTent
	waitmovement 0
	removeobject LOCALID_SLATEPORT_SCOTT
	addvar VAR_SCOTT_STATE, 1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	releaseall
	end

SlateportCity_Movement_PushPlayerDown:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

SlateportCity_Movement_PlayerWatchScottExit:
	delay_16
	walk_in_place_faster_right
	step_end

SlateportCity_Movement_ScottExitBattleTent:
	delay_8
	walk_down
	step_end

SlateportCity_Movement_ScottExitAfterBattleTent:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_EventScript_BerryCrushRankingsSign::
	lockall
	special ShowBerryCrushRankings
	releaseall
	end

SlateportCity_Text_EnergyGuruSellWhatYouNeed:
	.string "Ik ben de ENERGY GURU!\n"
	.string "Ik verkoop wat je nodig hebt!$"

SlateportCity_Text_OhYourPokemon:
	.string "O?\n"
	.string "Jouw {STR_VAR_1}...$"

SlateportCity_Text_PleaseGiveItThisEffortRibbon:
	.string "Wat heeft hij goed zijn best gedaan!\p"
	.string "Geef hem als beloning deze\n"
	.string "EFFORT RIBBON.$"

SlateportCity_Text_ReceivedEffortRibbon:
	.string "{PLAYER} krijgt de EFFORT RIBBON.$"

SlateportCity_Text_PutEffortRibbonOnMon:
	.string "{PLAYER} geeft de EFFORT RIBBON\n"
	.string "aan {STR_VAR_1}.$"

SlateportCity_Text_GoForItLittleHarder:
	.string "Je moet nog iets beter je best doen.\p"
	.string "Dan krijgt je POKéMON iets moois!$"

SlateportCity_Text_EffortRibbonLooksGoodOnIt:
	.string "Die EFFORT RIBBON staat\n"
	.string "jouw {STR_VAR_1} goed!$"

SlateportCity_Text_WonderIfLighthouseStartlesPokemon:
	.string "Het licht van de vuurtoren is\n"
	.string "van heel ver te zien.\p"
	.string "Zouden POKéMON in zee\n"
	.string "daarvan schrikken?$"

SlateportCity_Text_SeaweedFullOfLife:
	.string "Kijk eens! Dit zeewier is\n"
	.string "vers en zit vol leven.\p"
	.string "Het lijkt wel alsof het je\n"
	.string "zo kan aanvallen!$"

SlateportCity_Text_HowTownIsBornAndGrows:
	.string "Waar het water schoon is,\n"
	.string "is er veel voedsel.\p"
	.string "Waar mensen samenkomen,\n"
	.string "ontstaat vaak een markt.\p"
	.string "Zo groeit een stad!$"

SlateportCity_Text_SlateportWonderfulPlace:
	.string "Winkelen met de geur van de zee...\p"
	.string "SLATEPORT is zo'n fijne plek!$"

SlateportCity_Text_BuyBricksSoDecorWontGetDirty:
	.string "Poppen en kussens worden vuil\n"
	.string "als je ze op de grond legt.\p"
	.string "Ik koop stenen om ze\n"
	.string "op te zetten.$"

SlateportCity_Text_GoingToCompeteInBattleTent:
	.string "Ik ga ook meedoen in de BATTLE TENT!\p"
	.string "Maar eerst moet ik nog\n"
	.string "wat POKéMON vangen!$"

SlateportCity_Text_BushedHikingFromMauville:
	.string "Pfff, ik ben doodmoe!\p"
	.string "Ik ben vanuit MAUVILLE komen lopen.\n"
	.string "Wat is deze stad groot!\p"
	.string "Had ik maar mijn fiets gepakt.$"

SlateportCity_Text_EveryoneCallsHimCaptStern:
	.string "STERN heeft het museum gebouwd.\p"
	.string "Hij leidt ook een team dat\n"
	.string "de zeebodem onderzoekt.\p"
	.string "Iedereen noemt hem kapitein STERN.$"

SlateportCity_Text_WhatsLongLineOverThere:
	.string "Wat is dat daar?\n"
	.string "Wat een lange rij!$"

SlateportCity_Text_VisitedMuseumOften:
	.string "Als kind ging ik vaak\n"
	.string "naar het museum.\p"
	.string "Ik droomde dan over alle\n"
	.string "geheimen van de zee.$"

SlateportCity_Text_QuitPushing:
	.string "He, niet duwen!\n"
	.string "Zie je niet dat hier een rij is?$"

SlateportCity_Text_AquaHasPolicy:
	.string "Bij TEAM AQUA komen we samen\n"
	.string "op de plek van onze opdracht.\p"
	.string "Daar gaan we ook weer uit elkaar.$"

SlateportCity_Text_BossIsBrilliant:
	.string "Onze baas is heel slim.\p"
	.string "Wat zou hij met een museum willen?$"

SlateportCity_Text_WhatsNewSchemeIWonder:
	.string "Wat zou ons nieuwe plan zijn?\p"
	.string "Onze baas is eng als hij boos is.\n"
	.string "Ik kan maar beter niets verpesten.$"

SlateportCity_Text_ShouldTakeItAll:
	.string "Als er iets nuttigs in het museum\n"
	.string "is, moeten we alles meenemen!$"

SlateportCity_Text_DontButtIn:
	.string "He, jij daar!\n"
	.string "Bemoei je er niet mee!$"

SlateportCity_Text_RemindsMeOfLongLineForGames:
	.string "Wat een lange rij!\p"
	.string "Net als toen ik in de rij stond\n"
	.string "voor een populair spel.$"

SlateportCity_Text_WhyAreWeLiningUp:
	.string "Waarom staan we in de rij\n"
	.string "en moeten we betalen?\p"
	.string "We kunnen toch gewoon naar binnen?$"

SlateportCity_Text_WhatDoYouWant:
	.string "Wat?\n"
	.string "Wat wil je?$"

SlateportCity_Text_IllReadSignForYou:
	.string "Wil je dat bord lezen?\n"
	.string "Ik lees het wel voor!$"

SlateportCity_Text_SaysSomethingLikeSeaIsEndless:
	.string "Even kijken...\p"
	.string "Er staat iets over dat het leven\n"
	.string "in de zee eindeloos is.\p"
	.string "Ja, zoiets staat er vast.$"

SlateportCity_Text_ShouldveBroughtMyGameBoy:
	.string "Mopper, mopper...\p"
	.string "Had ik mijn Game Boy Advance\n"
	.string "maar meegenomen tegen de verveling.$"

SlateportCity_Text_HotSpringsAfterOperation:
	.string "Na deze opdracht neem ik jullie\n"
	.string "mee naar een warmwaterbad!\p"
	.string "Dat zei onze leider.\n"
	.string "Ik kan niet wachten!$"

SlateportCity_Text_SeaIsSoWet:
	.string "De zee is zo groot...\p"
	.string "Zou hij gemaakt zijn van\n"
	.string "de tranen van POKéMON?$"

SlateportCity_Text_SinkOldBoats:
	.string "Weet je wat ze met oude\n"
	.string "versleten schepen doen?\p"
	.string "Ze laten ze zinken, zodat\n"
	.string "POKéMON er kunnen wonen.$"

SlateportCity_Text_BuyTooMuch:
	.string "Elke keer als ik hier kom,\n"
	.string "koop ik veel te veel!$"

SlateportCity_Text_GetNameRaterToHelpYou:
	.string "Wil je de bijnaam van je POKéMON\n"
	.string "veranderen?\p"
	.string "Ga dan naar de NAME RATER.$"

SlateportCity_Text_CantChangeTradeMonName:
	.string "Je kunt de bijnaam van een\n"
	.string "geruilde POKéMON niet veranderen.\p"
	.string "Die naam is met liefde gekozen\n"
	.string "door zijn eerste trainer.$"

SlateportCity_Text_BattleTentBuiltRecently:
	.string "Er is pas een BATTLE TENT\n"
	.string "gebouwd in SLATEPORT.\p"
	.string "Gyms zijn leuk, maar dit ook!\p"
	.string "Zoek sterke POKéMON\n"
	.string "om daar te vechten!$"

SlateportCity_Text_CaptSternBeingInterviewed:
	.string "Ik hoopte op een beroemde ster\n"
	.string "voor een handtekening.\p"
	.string "Maar wie wordt daar geinterviewd?\n"
	.string "Is dat kapitein STERN?$"

SlateportCity_Text_InterviewerSoCool:
	.string "Die verslaggeefster is zo cool!\p"
	.string "Later wil ik ook verslaggever\n"
	.string "worden en de wereld rondreizen!$"

SlateportCity_Text_SternSaysDiscoveredSomething:
	.string "Kapitein STERN heeft iets ontdekt\n"
	.string "op de bodem van de zee.\p"
	.string "Wat zou het zijn?$"

SlateportCity_Text_CaptainComeBackWithBigFish:
	.string "Wat gebeurt hier?\p"
	.string "Heeft de kapitein een grote vis\n"
	.string "uit de diepe zee meegenomen?$"

SlateportCity_Text_AmIOnTV:
	.string "He! Kijk je?\n"
	.string "Ben ik op tv?$"

SlateportCity_Text_CaptainsACelebrity:
	.string "Een tv-interview, hier!\n"
	.string "De kapitein is beroemd!$"

SlateportCity_Text_BigSmileForCamera:
	.string "TY: Een grote glimlach voor\n"
	.string "de camera, kapitein STERN!$"

SlateportCity_Text_MostInvaluableExperience:
	.string "GABBY: Ik begrijp het.\n"
	.string "Wat een bijzondere ervaring!$"

SlateportCity_Text_SternMoveAheadWithExploration:
	.string "Kapitein STERN: Jazeker.\n"
	.string "We gaan verder met ons onderzoek.$"

SlateportCity_Text_GabbyWonderfulThanksForInterview:
	.string "GABBY: Geweldig, kapitein STERN!\n"
	.string "Bedankt voor uw tijd.\p"
	.string "We hopen u snel weer te spreken\n"
	.string "over nieuwe ontdekkingen!$"

SlateportCity_Text_SternWhewFirstInterview:
	.string "Kapitein STERN: Pfff...\p"
	.string "Dat was mijn eerste keer op tv.\n"
	.string "Wat was ik zenuwachtig!$"

SlateportCity_Text_OhPlayerWeMadeDiscovery:
	.string "O, {PLAYER}! Wat fijn je te zien!\p"
	.string "We hebben iets groots ontdekt\n"
	.string "tijdens onze laatste duik.\p"
	.string "Op ROUTE 128 vonden we\n"
	.string "een grot onder water.\p"
	.string "Misschien woont daar een POKéMON\n"
	.string "die al lang uitgestorven leek!$"

SlateportCity_Text_AquaWillAssumeControlOfSubmarine:
	.string "Hahaha... Kapitein STERN!\p"
	.string "TEAM AQUA neemt uw onderzeeër over!\p"
	.string "Verzet heeft geen zin.\n"
	.string "U moet gewoon meewerken!\p"
	.string "Kijk maar wat TEAM AQUA\n"
	.string "van plan is!$"

SlateportCity_Text_SternWhatWasAllThat:
	.string "Kapitein STERN: Wat was dat?\p"
	.string "Het klonk alsof iemand door\n"
	.string "een megafoon sprak.\p"
	.string "Waar kwam het vandaan?$"

SlateportCity_Text_FromHarborTryingToTakeSub:
	.string "Uit de haven!\p"
	.string "De onderzeeër!\n"
	.string "Ze proberen hem te stelen!$"

SlateportCity_Text_PleaseComeWithMe:
	.string "{PLAYER}!\n"
	.string "Kom alsjeblieft met me mee!$"

SlateportCity_Text_BattleTentSign:
	.string "BATTLE TENT SLATEPORT SITE\n"
	.string "“Find it! The ultimate POKéMON!”$"

SlateportCity_Text_SternsShipyardWantedSign:
	.string "STERN'S SHIPYARD\p"
	.string "“Wanted: A sailor capable of sailing\n"
	.string "in all currents.”$"

SlateportCity_Text_SternsShipyardNearsCompletion:
	.string "STERN'S SHIPYARD\p"
	.string "“The ferry S.S. TIDAL nears\n"
	.string "completion for serving the ports of\l"
	.string "SLATEPORT and LILYCOVE.”$"

SlateportCity_Text_SternsShipyardFerryComplete:
	.string "STERN'S SHIPYARD\p"
	.string "“Boarding of the SLATEPORT-LILYCOVE\n"
	.string "ferry S.S. TIDAL is handled at the\l"
	.string "HARBOR.”$"

SlateportCity_Text_PokemonFanClubSign:
	.string "POKéMON FAN CLUB\n"
	.string "“Calling all fans of POKéMON!”$"

SlateportCity_Text_OceanicMuseumSign:
	.string "“The endless sea sustains\n"
	.string "all life.”\p"
	.string "OCEANIC MUSEUM$"

SlateportCity_Text_CitySign:
	.string "SLATEPORT CITY\p"
	.string "“The port where people and POKéMON\n"
	.string "cross paths.”$"

SlateportCity_Text_MarketSign:
	.string "SLATEPORT MARKET\n"
	.string "“Unique items found nowhere else!”$"

SlateportCity_Text_HarborFerryUnderConstruction:
	.string "SLATEPORT HARBOR\p"
	.string "“The ferry S.S. TIDAL is under\n"
	.string "construction in the SHIPYARD.\p"
	.string "“Service is scheduled to begin\n"
	.string "shortly.”$"

SlateportCity_Text_HarborSign:
	.string "SLATEPORT HARBOR\p"
	.string "“Enjoy a delightful cruise on\n"
	.string "the ferry S.S. TIDAL.”$"

SlateportCity_Text_NameRatersHouseSign:
	.string "NAME RATER'S HOUSE\n"
	.string "“POKéMON nicknames rated.”$"

SlateportCity_Text_ExplainBerries:
	.string "Wilde POKéMON eten BERRIES\n"
	.string "om beter te worden.\p"
	.string "Daarom maken mensen medicijnen\n"
	.string "van BERRIES.\p"
	.string "Je moet ze eerst fijnmalen\n"
	.string "tot poeder.\p"
	.string "Vind je BERRIES interessant?\n"
	.string "Dan heb ik iets voor jou!$"

SlateportCity_Text_ExplainBerryPowder:
	.string "Boven in het POKéMON CENTER\n"
	.string "staan BERRY CRUSH machines.\p"
	.string "Daar kun je BERRIES fijnmalen.\p"
	.string "Breng mij BERRY POWDER.\n"
	.string "Dan maak ik er medicijnen van!$"

SlateportCity_Text_BroughtMeSomeBerryPowder:
	.string "Heb je BERRY POWDER\n"
	.string "voor me meegenomen?$"

SlateportCity_Text_ExchangeWhatWithIt:
	.string "Waar wil je het voor ruilen?$"

SlateportCity_Text_ExchangeBerryPowderForItem:
	.string "Wil je je BERRY POWDER ruilen\n"
	.string "voor een {STR_VAR_1}?$"

SlateportCity_Text_DontHaveEnoughBerryPowder:
	.string "Oei, je hebt niet genoeg\n"
	.string "BERRY POWDER.$"

SlateportCity_Text_FineBerryPowderTradeSomethingElse:
	.string "Mooi BERRY POWDER!\n"
	.string "Daar maak ik goede medicijnen van.\p"
	.string "Wil je nog iets ruilen?$"

SlateportCity_Text_WhenYouGetMoreBringItToMe:
	.string "Breng gerust meer BERRY POWDER\n"
	.string "als je het vindt!$"

SlateportCity_Text_ComeBackToTradeBerryPowder:
	.string "Kom terug als je BERRY POWDER\n"
	.string "voor medicijnen wilt ruilen.\p"
	.string "Ik sta altijd op deze markt!$"

SlateportCity_Text_YouDroveTeamAquaAway:
	.string "SCOTT: He? Ik heb jou toch\n"
	.string "al eens gezien?\p"
	.string "Ik heet SCOTT.\p"
	.string "Ik zag TEAM AQUA net hard wegrennen.\n"
	.string "Heb jij ze weggejaagd?$"

SlateportCity_Text_MaybeThisTrainer:
	.string "SCOTT: Hmm...\n"
	.string "Misschien is deze trainer wel...$"

SlateportCity_Text_LetsRegisterEachOther:
	.string "SCOTT: Volgens mij worden\n"
	.string "wij goede vrienden!\p"
	.string "Laten we elkaar toevoegen\n"
	.string "aan onze POKéNAVS.$"

SlateportCity_Text_RegisteredScott:
	.string "SCOTT is toegevoegd\n"
	.string "aan de POKéNAV.$"

SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou:
	.string "SCOTT: Ik zou graag met je meegaan.\p"
	.string "Maar ik wil ook andere goede\n"
	.string "trainers ontdekken.\p"
	.string "Ik ga nog wat steden bezoeken.\n"
	.string "Tot ziens, {PLAYER}!$"

SlateportCity_Text_TakingBattleTentChallenge:
	.string "SCOTT: He, {PLAYER}!\p"
	.string "Ga je meedoen in de BATTLE TENT?\n"
	.string "Wat een goed idee!\p"
	.string "Een sterke trainer past daar\n"
	.string "helemaal thuis.\p"
	.string "Doe je best!$"
