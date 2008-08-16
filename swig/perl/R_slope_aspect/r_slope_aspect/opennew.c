#include <stdlib.h>
#include <grass/gis.h>
#include <grass/glocale.h>


int opennew(char *name, RASTER_MAP_TYPE wr_type)
{
    int fd;

    if (wr_type < 0)		/* default fp type */
	fd = G_open_fp_cell_new(name);
    else
	fd = G_open_raster_new(name, wr_type);

    if (fd < 0)
	G_fatal_error(_("Failed in attempt to open %s"), name);

    return fd;
}
