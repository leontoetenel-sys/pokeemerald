RustboroCity_DevonCorp_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_3F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RustboroCity_DevonCorp_3F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_DevonCorp_3F_OnFrame
	.byte 0

RustboroCity_DevonCorp_3F_OnTransition:
	call_if_eq VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos
	end

RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos::
	setobjectxyperm LOCALID_DEVON_CORP_3F_EMPLOYEE, 3, 2
	setobjectmovementtype LOCALID_DEVON_CORP_3F_EMPLOYEE, MOVEMENT_TYPE_FACE_LEFT
	return

RustboroCity_DevonCorp_3F_OnWarp:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast::
	turnobject LOCALID_PLAYER, DIR_EAST
	end

RustboroCity_DevonCorp_3F_OnFrame:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_MeetPresident
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_MeetPresident::
	lockall
	msgbox RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen
	delay 80
	applywaitmovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer
	msgbox RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FOLLOW_ME, FALSE
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident
	applymovement LOCALID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_PleaseGoAhead, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk
	applymovement LOCALID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor, MSGBOX_DEFAULT
	giveitem ITEM_LETTER
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_3F_Text_ReceivedPokenav
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare, MSGBOX_DEFAULT
	setflag FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_BRINEY_LOCATION, 1
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setvar VAR_DEVON_CORP_3F_STATE, 1
	setvar VAR_RUSTBORO_CITY_STATE, 6
	releaseall
	end

RustboroCity_DevonCorp_3F_Movement_Unused:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk:
	delay_16
	walk_in_place_faster_down
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

RustboroCity_DevonCorp_3F_EventScript_MrStone::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EXP_SHARE, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, RustboroCity_DevonCorp_3F_EventScript_GiveExpShare
	msgbox RustboroCity_DevonCorp_3F_Text_CountingOnYou, MSGBOX_DEFAULT
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

RustboroCity_DevonCorp_3F_EventScript_GiveExpShare::
	msgbox RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_EXP_SHARE
	msgbox RustboroCity_DevonCorp_3F_Text_ExplainExpShare, MSGBOX_DEFAULT
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor::
	msgbox RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends, MSGBOX_DEFAULT
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

RustboroCity_DevonCorp_3F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REPEAT_BALL, RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls
	msgbox RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls::
	msgbox RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay::
	msgbox RustboroCity_DevonCorp_3F_Text_RareRocksDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor:
	.string "Ik ben meneer STONE, directeur\n"
	.string "van DEVON CORPORATION.\p"
	.string "Ik heb net over jou gehoord!\p"
	.string "Je hebt onze medewerker niet\n"
	.string "één, maar twee keer geholpen!\p"
	.string "Ik wil je graag iets vragen.\p"
	.string "Je brengt een pakket naar de\n"
	.string "scheepswerf in SLATEPORT, toch?\p"
	.string "Kun je onderweg ook stoppen\n"
	.string "in DEWFORD TOWN?\p"
	.string "Ik wil graag dat je een LETTER\n"
	.string "aan STEVEN geeft in DEWFORD.$"

RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis:
	.string "Meneer STONE: Ik ben natuurlijk\n"
	.string "een geweldige directeur.\p"
	.string "Ik vraag je niet zomaar om hulp\n"
	.string "zonder iets terug te geven.\p"
	.string "Daarom krijg je dit van mij!$"

RustboroCity_DevonCorp_3F_Text_ReceivedPokenav:
	.string "{PLAYER} krijgt een POKéNAV.$"

RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp:
	.string "Meneer STONE: Dat apparaat heet\n"
	.string "POKéMON NAVIGATOR, of POKéNAV.\p"
	.string "Het is heel handig voor trainers\n"
	.string "die op avontuur gaan.\p"
	.string "Er zit een kaart van HOENN in.\p"
	.string "Zo vind je DEWFORD en SLATEPORT\n"
	.string "heel makkelijk!\p"
	.string "Ik hoorde trouwens dat TEAM MAGMA\n"
	.string "en TEAM AQUA overal problemen\l"
	.string "veroorzaken.\p"
	.string "Rust eerst maar goed uit\n"
	.string "voor je verdergaat.$"

RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare:
	.string "Meneer STONE: Pas goed op jezelf\n"
	.string "onderweg, {PLAYER}!$"

RustboroCity_DevonCorp_3F_Text_CountingOnYou:
	.string "Meneer STONE: Ik reken op je!$"

RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter:
	.string "Meneer STONE: Heb je mijn LETTER\n"
	.string "bezorgd? Heel erg bedankt!\p"
	.string "Als dank krijg je iets dat\n"
	.string "je als trainer goed kunt gebruiken.$"

RustboroCity_DevonCorp_3F_Text_ExplainExpShare:
	.string "Meneer STONE: Een Pokémon die\n"
	.string "EXP. SHARE vasthoudt, krijgt\l"
	.string "een deel van de XP uit gevechten.\p"
	.string "Ook als hij zelf niet heeft\n"
	.string "meegevochten!\p"
	.string "Heel handig om zwakkere\n"
	.string "Pokémon te trainen.$"

RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends:
	.string "Meneer STONE: Ik werk al hard\n"
	.string "sinds ik jong was.\p"
	.string "Daardoor weet ik niet zo goed\n"
	.string "wat tegenwoordig populair is.\p"
	.string "Willen alle kinderen trainer\n"
	.string "worden in de POKéMON LEAGUE?$"

RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere:
	.string "Dit is de derde verdieping\n"
	.string "van DEVON CORPORATION.\p"
	.string "Hier is het kantoor van\n"
	.string "onze directeur.\p"
	.string "Ik ben je ontzettend dankbaar\n"
	.string "voor wat je hebt gedaan.\p"
	.string "Dat pakket dat je terughaalde...\p"
	.string "Wil je het naar de scheepswerf\n"
	.string "in SLATEPORT brengen?\p"
	.string "Het zou erg zijn als die dieven\n"
	.string "het opnieuw proberen te stelen.\p"
	.string "Hehe... Kan ik op je rekenen?\p"
	.string "O ja, wacht hier even, wil je?$"

RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe:
	.string "Onze directeur wil graag\n"
	.string "met je praten.\p"
	.string "Kom maar met me mee.$"

RustboroCity_DevonCorp_3F_Text_PleaseGoAhead:
	.string "Ga je gang.$"

RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard:
	.string "Ga bij de scheepswerf in\n"
	.string "SLATEPORT naar kapitein STERN.$"

RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular:
	.string "De nieuwe REPEAT BALL en\n"
	.string "TIMER BALL van DEVON zijn\l"
	.string "heel populair bij trainers.$"

RustboroCity_DevonCorp_3F_Text_RareRocksDisplay:
	.string "Een verzameling zeldzame stenen\n"
	.string "van onze directeur.$"

