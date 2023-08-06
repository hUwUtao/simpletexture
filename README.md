# `simpletexture`

A very simple image format. Optimized for games from scratch. (too lazy to make a lib, i'll put the spec below)

## Implementation


```c
FILE* fp = fopen("input.ft8", "rb");
fread(&width, sizeof(int), 1, fp);
fread(&height, sizeof(int), 1, fp);

for(int i = 0; i < height; i++) {
    char row[width * 3];
    fread(&row, sizeof(row), 1, fp);

    // [r, g, b, r, g, b, ...]
}

```
