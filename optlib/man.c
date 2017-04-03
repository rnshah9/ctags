/*
 * Generated by ./misc/optlib2c from optlib/man.ctags, Don't edit this manually.
 */
#include "general.h"
#include "parse.h"
#include "routines.h"


static void initializeManParser (const langType language CTAGS_ATTR_UNUSED)
{
}

extern parserDefinition* ManParser (void)
{
	static const char *const extensions [] = {
		"1",
		"2",
		"3",
		"4",
		"5",
		"6",
		"7",
		"8",
		"9",
		NULL
	};

	static const char *const aliases [] = {
		NULL
	};

	static const char *const patterns [] = {
		NULL
	};

	static kindDefinition ManKindTable [] = {
		{ true, 't', "title", "titles" },
		{ true, 's', "section", "sections" },
	};
	static tagRegexTable ManTagRegexTable [] = {
		{"^\\.TH[[:space:]]{1,}\"([^\"]{1,})\".*", "\\1",
		"t", "{exclusive}{icase}{scope=push}"},
		{"^\\.TH[[:space:]]{1,}([^[:space:]]{1,}).*", "\\1",
		"t", "{exclusive}{icase}{scope=push}"},
		{"^\\.SH[[:space:]]{1,}\"([^\"]{1,})\".*", "\\1",
		"s", "{exclusive}{icase}{scope=ref}"},
		{"^\\.SH[[:space:]]{1,}([^[:space:]]{1,}).*", "\\1",
		"s", "{exclusive}{icase}{scope=ref}"},
	};


	parserDefinition* const def = parserNew ("man");

	def->enabled       = false;
	def->extensions    = extensions;
	def->patterns      = patterns;
	def->aliases       = aliases;
	def->method        = METHOD_NOT_CRAFTED|METHOD_REGEX;
	def->kindTable = ManKindTable;
	def->kindCount = ARRAY_SIZE(ManKindTable);
	def->tagRegexTable = ManTagRegexTable;
	def->tagRegexCount = ARRAY_SIZE(ManTagRegexTable);
	def->initialize    = initializeManParser;

	return def;
}
