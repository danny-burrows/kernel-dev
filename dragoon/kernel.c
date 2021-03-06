// kernel.c

void kmain(void) {
    const char *str = "\
                    ^    ^                                                         \
                / \\  //\\                                                         \
 |\\___/|      /   \\//  .\\                                                       \
 /O  O  \\__  /    //  | \\ \\                                                     \
/     /  \\/_/    //   |  \\  \\                                                   \
@___@'    \\/_   //    |   \\   \\                                                 \
   |       \\/_ //     |    \\    \\                                               \
   |        \\///      |     \\     \\                                             \
  _|_ /   )  //       |      \\     _\\                                           \
 '/,_ _ _/  ( ; -.    |    _ _ \\.-~     .-~~~^-.                                \
 ,-{        _      `-.|.-~-.          .~         `.                            \
  '/\\      /                 ~-. _ .-~     .-~^-.   \\                           \
      `.   {            }                  /      \\   \\                         \
      .----~-.\\        \\-'               .~         \\  `.   \\^-.                \
    ///.----..>        \\             _ -~             `.  ^-`   ^-_             \
     ///-._ _ _ _ _ _ _}^ - - - - ~                     ~--,   .-~              \
                                                           /.-' ";

    char *vidptr = (char*)0xb8000;

    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int screensize;

    screensize =  80 * 25 * 2;
    while (j < screensize) {
        vidptr[j] = ' ';

        vidptr[j+1] = 0x07;

        j = j + 2;
    }

    j = 0;

    while (str[j] != '\0') {
        vidptr[i] = str[j];

        vidptr[i+1] = 0x0c;

        ++j;
        i = i + 2;
    }

    return;
}