#include <stdlib.h>
//#include <windows.h>
#include "libs\nstd_string\nstd_string.h"
#include "libs\autoexec_creator\autoexec_creator.h"

char* config_file_string[4];
const char cfg_directory[] = "C:\\Program Files (x86)\\Steam\\userdata\\USER_NUMBER\\730\\local\\cfg";
const char* const file_name[] =
{
	"cs2_machine_convars.vcfg",
	"cs2_user_convars_0_slot0.vcfg",
	"cs2_user_keys_0_slot0.vcfg"
};

int main()
{
	FILE* autoexec = fopen("autoexec.cfg", "wb");
	char c;

	//SetCurrentDirectory(cfg_directory);

 	config_file_string[0] = copy_file_to_string(file_name[0]);
 	config_file_string[1] = copy_file_to_string(file_name[1]);
 	config_file_string[2] = copy_file_to_string(file_name[2]);
 	config_file_string[3] = NULL;

	printf("\nPress ENTER if main.exe is located in:\t\"%s\"", cfg_directory);
	printf("\nIf not, Q + ENTER to quit:\t");
	c = getchar();
	if (TO_UPPER(c) == 'Q')
		return 0;

	write_autoexec(config_file_string, autoexec);
	fclose(autoexec);

	printf("\nPress ENTER");
	getchar();

	return 0;
}