// Start in CodeBlock x64 compiler
.data msg
    :.string "Number:\t6\nGroup:\tPIN-23\nTeam:\tMisha Suhanov | Islamov "
             "Radmir\n\n\0" input_16 :.string "%hd%hd" input_32
    :.string "%d%d" input_64 :.string "%lld%lld" input_float
    :.string "%f%f" input_double :.string "%lf%lf" output_16
    :.string "16 bit:\nNumber X = %hd\nNumber Y = %hd\n\n" output_32
    :.string "32 bit:\nNumber X = %d\nNumber Y = %d\n\n" output_64
    :.string "64 bit:\nNumber X = %lld\nNumber Y = %lld\n\n" output_float
    :.string "FLOAT:\nNumber X = %f\nNumber Y = %f\n\n" output_double
    :.string "DOUBLE:\nNumber X = %lf\nNumber Y = %lf\n\n" output_atan2
    :.string "atan2(Y / X) = %lf\n\n" output4
    :.string "%hd\t"

     valx_16 :.short 0 valy_16 :.short 0 valx_32 :.int 0 valy_32
    :.int 0 valx_64 :.quad 0 valy_64 :.quad 0 valx_float
    :.float 0.0 valy_float :.float 0.0 valx_double :.double 0.0 valy_double
    :.double 0.0.text.globl main

         main :
    // Microsoft Windows 64 || Разрядность сборки: 64-bit
    sub $8,
    % rsp

            // Ex_1 =================================
            lea msg(% rip),
    % rbx movq % rbx, % rcx sub $32, % rsp call puts add $32, % rsp xor % rax,
    % rax
        //======================================

        // Ex_2 =================================
        lea input_16(% rip),
    %
        rbx
        //>>>> 16 bit <<<<

        movq
        % rbx,
    % rcx leaq valx_16(% rip), % rdx leaq valy_16(% rip), % r8 movb $3,
    % al sub $32, % rsp call scanf add $32, % rsp xor % eax,
    % eax

        lea output_16(% rip),
    %
        rbx

        movq
        % rbx,
    % rcx movw valx_16(% rip), % dx movw valy_16(% rip), % r8w sub $32,
    % rsp call printf add $32, % rsp xor % eax, % eax

                                                    lea input_32(% rip),
    %
        rbx
        //>>>> 32 bit <<<<

        movq
        % rbx,
    % rcx leaq valx_32(% rip), % rdx leaq valy_32(% rip), % r8 movb $3,
    % al sub $32, % rsp call scanf add $32, % rsp xor % eax,
    % eax

        lea output_32(% rip),
    % rbx movq valx_32(% rip), % rdx movq valy_32(% rip), % r8 movq % rbx,
    % rcx sub $32, % rsp call printf add $32, % rsp xor % eax,
    % eax

        lea input_64(% rip),
    %
        rbx
        //>>>> 64 bit <<<<

        movq
        % rbx,
    % rcx leaq valx_64(% rip), % rdx leaq valy_64(% rip), % r8 movb $3,
    % al sub $32, % rsp call scanf add $32, % rsp xor % eax,
    % eax

        lea output_64(% rip),
    %
        rbx

        movq
        % rbx,
    % rcx movq valx_64(% rip), % rdx movq valy_64(% rip), % r8 sub $32,
    % rsp call printf add $32, % rsp xor % eax, % eax

                                                    lea input_float(% rip),
    %
        rbx
        //>>>> FLOAT <<<<

        movq
        % rbx,
    % rcx lea valx_float(% rip), % rdx lea valy_float(% rip), % r8 sub $32,
    % rsp call scanf add $32, % rsp xor % eax, % eax

                                                   lea output_float(% rip),
    %
        rbx

        mov
        % rbx,
    % rcx CVTSS2sd valx_float(% rip), % xmm0 CVTSS2sd valy_float(% rip),
    %
        xmm1
        // movlhps %xmm0, %xmm0
        movq
        % xmm0,
    %
        rdx
        // movlhps %xmm1, %xmm1
        movq
        % xmm1,
    % r8 sub $32, % rsp call printf add $32, % rsp xor % eax,
    % eax

        lea input_double(% rip),
    %
        rbx
        //>>>> DOUBLE <<<<

        movq
        % rbx,
    % rcx leaq valx_double(% rip), % rdx leaq valy_double(% rip), % r8 sub $32,
    % rsp call scanf add $32, % rsp xor % eax, % eax

                                                   lea output_double(% rip),
    %
        rbx

        movq
        % rbx,
    % rcx movsd valx_double(% rip), % xmm0 movsd valy_double(% rip),
    % xmm1 vmovlhps % xmm0, % xmm0, % xmm0 movq % xmm0, % rdx vmovlhps % xmm1,
    % xmm1, % xmm1 movq % xmm1, % r8 sub $32, % rsp call printf add $32,
    % rsp xor % eax, % eax
                         //======================================

                         // Ex_3 =================================
                         lea input_double(% rip),
    %
        rbx

        movq
        % rbx,
    % rcx leaq valx_double(% rip), % rdx leaq valy_double(% rip), % r8 movb $3,
    % al sub $32, % rsp call scanf add $32, % rsp xor % eax,
    % eax

        movsd valx_double(% rip),
    % xmm0 movsd valy_double(% rip), % xmm1 sub $32, % rsp call atan2 add $32,
    % rsp movq % xmm0, % xmm2 xor % rax, % rax

                                             lea output_atan2(% rip),
    %
        rbx

        movq
        % rbx,
    % rcx vmovq % xmm2, % rdx sub $32, % rsp call printf add $32,
    % rsp xor % eax, % eax
                         //======================================

                         // Ex_4 =================================
                         lea input_64(% rip),
    %
        rbx

        movq
        % rbx,
    % rcx leaq valx_16(% rip), % rdx leaq valy_16(% rip), % r8 movb $3,
    % al sub $32, % rsp call scanf add $32, % rsp xor % eax,
    % eax

        lea output4(% rip),
    %
        rbx

        movq
        % rbx,
    % r8 movw valx_16(% rip), % cx movw valy_16(% rip), % dx sub $32,
    % rsp call numbers add $32, % rsp movq % rax, %
                                                      r12

                                                      movq
                                                      % rbx,
    % rcx movq % r12, % rdx movb $2, % al sub $32, % rsp call printf add $32,
    % rsp xor % eax, % eax
                         //======================================

                         add $8,
    % rsp

        ret

        numbers :
    /*
        cx  - signed byte N > 0
        dx - unsigned short x0
        r8  - string format
    */

    sub $16,
    %
        rsp

        push
        % rbx push %
        r12

        mov
        % dx,
    %
        bx

        a1 : movw
             %
             bx,
    % ax movl $2, % r12d xor % edx, % edx div % r12d cmp $1, % edx

                                                                 jnz if0 jz if1

                                                                 if0 : shrw $1,
    % bx jmp label if1 : mov % ebx, % eax xor % rdx, % rdx mov $3,
    % dx mul % dx add $1, % ax mov % ax, %
                                             bx jmp label

                                             label :

    push
    %
    rcx push % rdx push %
    r8

    movw
    %
    bx,
    % dx movq % r8, % rcx movb $2, % al sub $32, % rsp call printf add $32,
    % rsp xor % rax, %
                         rax

                         pop
                         % r8 pop % rdx pop %
                         rcx

                         dec
                         % rcx cmp $0,
    %
            cx jnz a1

            pop
            % r12 pop % rbx

        xor % rax,
    % rax add $16, % rsp

                       ret
