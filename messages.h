struct messages
{
    PANEL panel;
    _Bool type, select;
    uint16_t urlover, urllen;
    uint32_t height;
    uint32_t iover, over, idown, down;
    MSG_DATA *data;
};

typedef struct {
    uint16_t flags, height, length;
    wchar_t msg[1];
} MESSAGE;

typedef struct {
    uint16_t flags, height;
    HBITMAP bitmap;
} MSG_IMG;

typedef struct {
    uint16_t flags, height;
    uint8_t filenumber, status, name_length;
    uint64_t size, progress;
    uint8_t name[24];
} MSG_FILE;

void messages_draw(MESSAGES *m, int x, int y, int width, int height);
_Bool messages_mmove(MESSAGES *m, int mx, int my, int dy, int width, int height);
_Bool messages_mdown(MESSAGES *m);
_Bool messages_mright(MESSAGES *m);
_Bool messages_mwheel(MESSAGES *m, int height, double d);
_Bool messages_mup(MESSAGES *m);
_Bool messages_mleave(MESSAGES *m);

void messages_copy(MESSAGES *m);

void message_setheight(MESSAGES *m, MESSAGE *msg, MSG_DATA *p);
void message_updateheight(MESSAGES *m, MESSAGE *msg, MSG_DATA *p);
void message_add(MESSAGES *m, MESSAGE *msg, MSG_DATA *p);
