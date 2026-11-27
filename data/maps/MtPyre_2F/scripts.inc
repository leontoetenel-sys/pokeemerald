MtPyre_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_2F_SetHoleWarp
	.byte 0

MtPyre_2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_MT_PYRE_1F
	end

MtPyre_2F_EventScript_Woman::
	msgbox MtPyre_2F_Text_MemoriesOfSkitty, MSGBOX_NPC
	end

MtPyre_2F_EventScript_PokefanM::
	msgbox MtPyre_2F_Text_TumbledFromFloorAbove, MSGBOX_NPC
	end

MtPyre_2F_EventScript_Mark::
	trainerbattle_single TRAINER_MARK, MtPyre_2F_Text_MarkIntro, MtPyre_2F_Text_MarkDefeat
	msgbox MtPyre_2F_Text_MarkPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Luke::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_LukeIntro, MtPyre_2F_Text_LukeDefeat, MtPyre_2F_Text_LukeNotEnoughMons
	msgbox MtPyre_2F_Text_LukePostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Dez::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_DezIntro, MtPyre_2F_Text_DezDefeat, MtPyre_2F_Text_DezNotEnoughMons
	msgbox MtPyre_2F_Text_DezPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Leah::
	trainerbattle_single TRAINER_LEAH, MtPyre_2F_Text_LeahIntro, MtPyre_2F_Text_LeahDefeat
	msgbox MtPyre_2F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Zander::
	trainerbattle_single TRAINER_ZANDER, MtPyre_2F_Text_ZanderIntro, MtPyre_2F_Text_ZanderDefeat
	msgbox MtPyre_2F_Text_ZanderPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_Text_MemoriesOfSkitty:
	.string "Herinneringen aan mijn\nlieve SKITTY...\p"
	.string "Als ik eraan denk, moet ik huilen.$"

MtPyre_2F_Text_TumbledFromFloorAbove:
	.string "Au, au... Er zitten hier en daar\n"
	.string "gaten in de vloer.\p"
	.string "Ik zag er eentje niet en viel\n"
	.string "van de verdieping hierboven.$"

MtPyre_2F_Text_MarkIntro:
	.string "Hé! Zoek jij POKéMON?\n"
	.string "Ik was hier eerst! Wat onbeleefd!$"

MtPyre_2F_Text_MarkDefeat:
	.string "Aaaah!\n"
	.string "Sorry, vergeef me alsjeblieft!$"

MtPyre_2F_Text_MarkPostBattle:
	.string "Hier komen niet vaak mensen,\n"
	.string "dus ik hoopte op zeldzame POKéMON.$"

MtPyre_2F_Text_LukeIntro:
	.string "LUKE: We zijn hier vanwege\n"
	.string "een weddenschap.\p"
	.string "Als ik laat zien hoe stoer ik ben,\n"
	.string "wordt ze vast verliefd op me!\p"
	.string "Ik weet het! Ik versla jou\n"
	.string "en laat zien hoe stoer ik ben!$"

MtPyre_2F_Text_LukeDefeat:
	.string "LUKE: Oepsie!$"

MtPyre_2F_Text_LukePostBattle:
	.string "LUKE: We verloren, maar dat\n"
	.string "geeft niet! Ik ben bij je.\p"
	.string "Samen halen we het einde van\n"
	.string "deze weddenschap!$"

MtPyre_2F_Text_LukeNotEnoughMons:
	.string "LUKE: Als je tegen ons wilt\n"
	.string "vechten, neem dan meer POKéMON mee.\p"
	.string "Anders kan ik mijn vriendin\n"
	.string "niet laten zien hoe stoer ik ben!$"

MtPyre_2F_Text_DezIntro:
	.string "DEZ: Ik ben hier met mijn vriend\n"
	.string "voor een weddenschap.\p"
	.string "Het is eng, maar mijn vriend\n"
	.string "is bij me. Het komt goed.\p"
	.string "Ik weet het! Hij kan laten zien\n"
	.string "hoe stoer hij is en van je wint!$"

MtPyre_2F_Text_DezDefeat:
	.string "DEZ: Waaaah! Ik ben bang!$"

MtPyre_2F_Text_DezPostBattle:
	.string "DEZ: We zijn verliefd, dus het\n"
	.string "maakt niet uit dat we verliezen!$"

MtPyre_2F_Text_DezNotEnoughMons:
	.string "DEZ: Als je ons wilt uitdagen,\n"
	.string "heb je twee POKéMON nodig.\p"
	.string "Mijn vriend is sterk. Met maar\n"
	.string "één POKéMON red je het niet.$"

MtPyre_2F_Text_LeahIntro:
	.string "Jou ken ik niet...\n"
	.string "Ga weg voordat je iets overkomt!$"

MtPyre_2F_Text_LeahDefeat:
	.string "Hmm...\n"
	.string "Jij kunt wel wat hebben.$"

MtPyre_2F_Text_LeahPostBattle:
	.string "Mijn familie traint hier al sinds\n"
	.string "de tijd van mijn overgrootmoeder.\p"
	.string "Het is mijn taak om deze\n"
	.string "berg te beschermen...$"

MtPyre_2F_Text_ZanderIntro:
	.string "Aaaah!\n"
	.string "Ik ben doodsbang!$"

MtPyre_2F_Text_ZanderDefeat:
	.string "Neeee!\n"
	.string "Ik ben helemaal in de war!$"

MtPyre_2F_Text_ZanderPostBattle:
	.string "Ik schrik telkens als ik\n"
	.string "iets zie bewegen...\p"
	.string "Ik had hier niet moeten\n"
	.string "komen trainen...$"

