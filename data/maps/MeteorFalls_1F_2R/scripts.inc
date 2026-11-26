MeteorFalls_1F_2R_MapScripts::
	.byte 0

MeteorFalls_1F_2R_EventScript_Nicolas::
	trainerbattle_single TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasIntro, MeteorFalls_1F_2R_Text_NicolasDefeat, MeteorFalls_1F_2R_EventScript_RegisterNicolas
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchNicolas
	msgbox MeteorFalls_1F_2R_Text_NicolasPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterNicolas::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MeteorFalls_1F_2R_Text_NicolasRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLAS_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchNicolas::
	trainerbattle_rematch TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasRematchIntro, MeteorFalls_1F_2R_Text_NicolasRematchDefeat
	msgbox MeteorFalls_1F_2R_Text_NicolasPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_John::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnIntro, MeteorFalls_1F_2R_Text_JohnDefeat, MeteorFalls_1F_2R_Text_JohnNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJohn
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJohn
	msgbox MeteorFalls_1F_2R_Text_JohnPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJohn::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJohn::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnRematchIntro, MeteorFalls_1F_2R_Text_JohnRematchDefeat, MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JohnPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_Jay::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayIntro, MeteorFalls_1F_2R_Text_JayDefeat, MeteorFalls_1F_2R_Text_JayNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJay
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJay
	msgbox MeteorFalls_1F_2R_Text_JayPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJay::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT  @ John speaks for both during register
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJay::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayRematchIntro, MeteorFalls_1F_2R_Text_JayRematchDefeat, MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JayPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_Text_NicolasIntro:
	.string "Hier trainen wij met Pokémon\n"
	.string "van het DRAGON-type.\p"
	.string "Zelfs de kampioen komt hier.\n"
	.string "Snap je nu hoe bijzonder dit is?$"

MeteorFalls_1F_2R_Text_NicolasDefeat:
	.string "Oef!\n"
	.string "Ik wist niet dat je zo sterk was!$"

MeteorFalls_1F_2R_Text_NicolasPostBattle:
	.string "We hebben nog een lange,\n"
	.string "moeilijke weg te gaan.\p"
	.string "Wanneer worden mijn Pokémon\n"
	.string "en ik de allerbesten?$"

MeteorFalls_1F_2R_Text_NicolasRegister:
	.string "Ik wil meer weten over jouw kracht.\n"
	.string "Ik registreer je in mijn PokéNav.$"

MeteorFalls_1F_2R_Text_NicolasRematchIntro:
	.string "Sinds onze ontmoeting hebben\n"
	.string "we hard getraind om de beste\l"
	.string "te worden.\p"
	.string "Laat ons zien hoeveel sterker\n"
	.string "we zijn geworden!$"

MeteorFalls_1F_2R_Text_NicolasRematchDefeat:
	.string "Oef!\n"
	.string "Ik wist niet dat je zo sterk was!$"

MeteorFalls_1F_2R_Text_NicolasPostRematch:
	.string "Jij bent duidelijk blijven\n"
	.string "trainen met je Pokémon.\p"
	.string "Zolang jij sterk blijft, kan\n"
	.string "ik ook steeds sterker worden!$"

MeteorFalls_1F_2R_Text_JohnIntro:
	.string "JOHN: Wij vechten altijd\n"
	.string "samen met onze Pokémon.\p"
	.string "We hebben vertrouwen in onszelf.$"

MeteorFalls_1F_2R_Text_JohnDefeat:
	.string "JOHN: O jeetje.\n"
	.string "We hebben verloren, liefste.$"

MeteorFalls_1F_2R_Text_JohnPostBattle:
	.string "JOHN: We zijn al vijftig jaar\n"
	.string "getrouwd.\p"
	.string "Nu ik erover nadenk, heb ik\n"
	.string "mijn lieve vrouw nog nooit\l"
	.string "verslagen in een duel.$"

MeteorFalls_1F_2R_Text_JohnNotEnoughMons:
	.string "JOHN: Wat een jonge trainer!\p"
	.string "Wil je tegen ons vechten?\n"
	.string "Kom dan terug met meer Pokémon.$"

MeteorFalls_1F_2R_Text_JohnRegister:
	.string "JOHN: Jonge trainer, wil je\n"
	.string "nog eens tegen ons vechten\l"
	.string "als je de kans krijgt?$"

MeteorFalls_1F_2R_Text_JayIntro:
	.string "JAY: We zijn al vijftig jaar\n"
	.string "getrouwd.\p"
	.string "Niets kan de band tussen\n"
	.string "ons verbreken.$"

MeteorFalls_1F_2R_Text_JayDefeat:
	.string "JAY: O jeetje.\n"
	.string "We hebben verloren, liefste.$"

MeteorFalls_1F_2R_Text_JayPostBattle:
	.string "JAY: Vijftig jaar getrouwd...\p"
	.string "Als we ruzie hadden, losten we\n"
	.string "dat altijd op met een Pokémon-duel.$"

MeteorFalls_1F_2R_Text_JayNotEnoughMons:
	.string "JAY: Wat een jonge trainer!\p"
	.string "Wil je tegen ons vechten?\n"
	.string "Kom dan terug met meer Pokémon.$"

MeteorFalls_1F_2R_Text_JohnRematchIntro:
	.string "JOHN: Wij vechten altijd\n"
	.string "samen met onze Pokémon.\p"
	.string "We hebben vertrouwen in onszelf.$"

MeteorFalls_1F_2R_Text_JohnRematchDefeat:
	.string "JOHN: O jeetje.\n"
	.string "We hebben verloren, liefste.$"

MeteorFalls_1F_2R_Text_JohnPostRematch:
	.string "JOHN: Vijftig jaar getrouwd...\p"
	.string "Als ik eraan terugdenk, hebben\n"
	.string "mijn lieve vrouw en ik dag in,\l"
	.string "dag uit tegen elkaar gevochten.$"

MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons:
	.string "JOHN: Wat een jonge trainer!\p"
	.string "Wil je tegen ons vechten?\n"
	.string "Kom dan terug met meer Pokémon.$"

MeteorFalls_1F_2R_Text_JayRematchIntro:
	.string "JAY: We zijn al vijftig jaar\n"
	.string "getrouwd.\p"
	.string "Al die tijd steunden we elkaar.\n"
	.string "Samen zijn we sterk geworden.$"

MeteorFalls_1F_2R_Text_JayRematchDefeat:
	.string "JAY: O jeetje.\n"
	.string "We hebben verloren, liefste.$"

MeteorFalls_1F_2R_Text_JayPostRematch:
	.string "JAY: Vijftig jaar getrouwd...\n"
	.string "We hebben veel meegemaakt.\p"
	.string "Ik hoop dat we samen nog veel\n"
	.string "mooie herinneringen maken.$"

MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons:
	.string "JAY: Wat een jonge trainer!\p"
	.string "Wil je tegen ons vechten?\n"
	.string "Kom dan terug met meer Pokémon.$"

