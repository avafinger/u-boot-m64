
#include <common.h>

DECLARE_GLOBAL_DATA_PTR;

int get_model_from_dram_size(char* model)
{
	phys_size_t l = 512 * 1024 * 1024;
	puts("Detect: A64 model by DRAM size\n");
	if (gd->ram_size == l) {
		sprintf(model, "512M");
	} else {
		l *= 2;
		if (gd->ram_size == l) {
			sprintf(model, "1GB");
		} else {
			sprintf(model, "2GB");
		}
	}

	return 0;
}

int a64_set_model(void)
{
	char model[128] = {0};
	get_model_from_dram_size(model);

	printf("A64 model: %s\n", model);
	if(setenv("a64_model", model))
	{
		printf("error:set variable [a64_model] fail\n");
	}
	return 0;
}
