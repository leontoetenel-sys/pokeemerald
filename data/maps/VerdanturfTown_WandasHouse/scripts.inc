VerdanturfTown_WandasHouse_MapScripts::
	.byte 0

VerdanturfTown_WandasHouse_EventScript_Wally::
	lock
	faceplayer
	goto_if_set FLAG_WALLY_SPEECH, VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeech, MSGBOX_DEFAULT
	setflag FLAG_WALLY_SPEECH
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech::
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeechShort, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff
	msgbox VerdanturfTown_WandasHouse_Text_WallysNextDoor, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff::
	msgbox VerdanturfTown_WandasHouse_Text_WallySlippedOff, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyGoneThatFar, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandasBoyfriend::
	msgbox VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay, MSGBOX_NPC
	end

VerdanturfTown_WandasHouse_EventScript_Wanda::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WandaDontWorry
	goto_if_set FLAG_DEFEATED_WALLY_MAUVILLE, VerdanturfTown_WandasHouse_EventScript_MeetWanda
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_MeetWanda::
	msgbox VerdanturfTown_WandasHouse_Text_MeetWanda, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandaDontWorry::
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAunt::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen::
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened::
	msgbox VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_Text_StrongerSpeech:
	.string "WALLY: Ik verloor van je, {PLAYER},\n"
	.string "maar ik ben niet meer verdrietig.\p"
	.string "Ik heb nu een nieuw doel!\n"
	.string "Samen met mijn RALTS ga ik\l"
	.string "GYMS uitdagen en een geweldige\l"
	.string "trainer worden.\p"
	.string "Let maar op, {PLAYER}.\n"
	.string "Ik word sterker dan jij!\p"
	.string "Dan daag ik je opnieuw uit\n"
	.string "voor een duel.$"

VerdanturfTown_WandasHouse_Text_StrongerSpeechShort:
	.string "WALLY: Let maar op, {PLAYER}.\n"
	.string "Ik word sterker dan jij!\p"
	.string "Dan daag ik je opnieuw uit\n"
	.string "voor een duel.$"

VerdanturfTown_WandasHouse_Text_WallysNextDoor:
	.string "OOM: O, {PLAYER}!\n"
	.string "WALLY is hiernaast.\p"
	.string "Maar ik moet je iets vertellen.\p"
	.string "De natuur hier doet wonderen\n"
	.string "voor zijn gezondheid.\p"
	.string "Misschien ligt het niet alleen\n"
	.string "aan de natuur.\p"
	.string "Misschien geven de Pokémon\n"
	.string "hem nieuwe hoop.$"

VerdanturfTown_WandasHouse_Text_WallySlippedOff:
	.string "WALLY is weg...\n"
	.string "Hij is alleen vertrokken...$"

VerdanturfTown_WandasHouse_Text_WallyGoneThatFar:
	.string "OOM: Echt waar?\n"
	.string "Is WALLY helemaal alleen\l"
	.string "zo ver gekomen?\p"
	.string "Knap van hem! Hij is tenslotte\n"
	.string "de zoon van mijn broertje.$"

VerdanturfTown_WandasHouse_Text_MeetWanda:
	.string "WANDA: Wie ben jij?\n"
	.string "O, natuurlijk!\p"
	.string "Jij bent {PLAYER}, over wie\n"
	.string "WALLY me vertelde.\p"
	.string "Ik ben zijn nicht.\n"
	.string "Leuk je te ontmoeten!\p"
	.string "WALLY is veel vrolijker en\n"
	.string "gezonder sinds hij hier woont.$"

VerdanturfTown_WandasHouse_Text_DontWorryAboutWally:
	.string "WANDA: Maak je geen zorgen\n"
	.string "om WALLY. Het komt wel goed.\p"
	.string "Ik ken mijn neefje. Bovendien\n"
	.string "heeft hij zijn Pokémon bij zich.$"

VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay:
	.string "Dankzij jou kan ik mijn vriendin\n"
	.string "elke dag zien.\p"
	.string "Blij? Nou en of!$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven:
	.string "De vriend van mijn dochter\n"
	.string "is heel vastberaden.\p"
	.string "Hij graaft maar door aan een\n"
	.string "tunnel om haar te kunnen zien.\p"
	.string "Mijn dochter maakt zich zorgen.\n"
	.string "Ze gaat vaak naar de tunnel.$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging:
	.string "Ongelooflijk! De vriend van mijn\n"
	.string "dochter groef de tunnel met\l"
	.string "zijn blote handen!\p"
	.string "Wat bijzonder!$"

VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally:
	.string "Als WALLY iets zou overkomen,\n"
	.string "durf ik zijn ouders in PETALBURG\l"
	.string "nooit meer aan te kijken...$"

VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande:
	.string "Was WALLY in EVER GRANDE?\p"
	.string "Zijn ouders in PETALBURG\n"
	.string "zullen verbaasd zijn!$"

