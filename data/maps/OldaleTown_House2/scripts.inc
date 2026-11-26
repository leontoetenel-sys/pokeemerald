OldaleTown_House2_MapScripts::
	.byte 0

OldaleTown_House2_EventScript_Woman::
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man::
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp:
	.string "Door te vechten gaan Pokémon\n"
	.string "levels omhoog en worden ze sterker.$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon:
	.string "Als je Pokémon sterker worden,\n"
	.string "kun je steeds verder reizen.$"

