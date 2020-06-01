add_library(tinycbor
    tinycbor/src/cborerrorstrings.c
    tinycbor/src/cborencoder.c
    tinycbor/src/cborencoder_close_container_checked.c
    tinycbor/src/cborparser.c
    tinycbor/src/cborparser_dup_string.c
    tinycbor/src/cborpretty.c
    tinycbor/src/cborpretty_stdio.c
    tinycbor/src/cborvalidation.c
    )
disable_clang_tidy(tinycbor)