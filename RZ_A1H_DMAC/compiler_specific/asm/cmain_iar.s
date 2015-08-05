/**************************************************
 *
 * Part two of the system initialization code, contains C-level
 * initialization.
 *
 * Copyright 2006 IAR Systems. All rights reserved.
 *
 * $Revision: 62134 $
 *
 **************************************************/


; --------------------------------------------------
; Module ?cmain, C-level initialization.
;

        MODULE  ?cmain

        SECTION SHT$$PREINIT_ARRAY:CONST:NOROOT(2)
        SECTION SHT$$INIT_ARRAY:CONST:NOROOT(2)

; ----------------------------------------
; This is where cstartup (part one of the initialization code) jumps
; when done.
;

        SECTION .text:CODE:NOROOT(2)

        PUBLIC  __cmain
        ;; Keep ?main for legacy reasons, it is accessed in countless instances of cstartup.s around the world...
        PUBLIC  ?main
        PUBLIC  _main
        EXTWEAK __iar_data_init3
        EXTWEAK __iar_argc_argv
        EXTERN  __low_level_init
        EXTERN  __call_ctors
        EXTERN  main
        EXTERN  exit

        ARM
__cmain:
?main:
        REQUIRE ?jump_to_main

        MOV     r0,#1
          FUNCALL __cmain, __low_level_init
        BL      __low_level_init

        CMP     r0, #0
        BEQ     ?init_done        ; __iar_data_init3 is THUMB: avoid veneer
          FUNCALL __cmain, __iar_data_init3
        BL      __iar_data_init3
?init_done:


; ----------------------------------------
; Call the "main" function (i.e. the user application). If it returns
; call "exit". Should that too return call our low-level termination
; function "_exit". As a final resort, call the function responsible
; for halting the application "__exit" (repeatedly).
;

        SECTION .text:CODE:NOROOT(2)
        PUBLIC _call_main
        EXTERN  __exit

        ARM

__iar_init$$done:               ; Copy initialization is done

?jump_to_main:
_call_main:
        MOV     r0, #0                  ; argc, no parameters.

          FUNCALL __cmain,__iar_argc_argv
        BL      __iar_argc_argv         ; Maybe setup command line
_main:        
          FUNCALL __cmain, main
        BL      main

          FUNCALL __cmain, exit
        BL      exit

exit_loop
          FUNCALL __cmain, __exit
        BL      __exit
        B       exit_loop

        END
