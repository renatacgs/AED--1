#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Pilha.h"

int validacao_escopo (char *exp){
    int i = 0;
    Pilha pe;
    pe = cria_pilha();
    Tipo_dado *elem,elem_aux;
    elem = (Tipo_dado*)malloc(sizeof(Tipo_dado));

    while (exp[i] != '\0'){
        elem->info = ' ';

        //verifica a abertura de parenteses, colchetes e chaves em sua ordem de prioridade.
        if(exp[i] == '('){
            elem_aux.info = exp[i];
            push(&pe,elem_aux);
        }
        if(exp[i] == '[' ){
            le_topo(pe,elem);
            if(elem->info == '('){
                printf("Eh necessario fazer o fechamento de todos os parenteses para abrir um colchete!");
                return 0;
            }
            elem_aux.info = exp[i];
            push(&pe,elem_aux);
        }
        if(exp[i] == '{'){
            le_topo(pe,elem);
            if(elem->info == '('){
                printf("Eh necessario fazer o fechamento de todos os parenteses para abrir uma chave!");
                return 0;
            }
            if(elem->info == '['){
                printf("Eh necessario fazer o fechamento de todos os colchetes para abrir uma chave!");
                return 0;
            }
            elem_aux.info = exp[i];
            push(&pe,elem_aux);
        }


        // verifica o fechamento dos parentese,  colchetes e chaves
        if(exp[i] == ')'){
            if(pop(&pe,elem)){
                if(elem->info == '[' ){
                    printf("Algum colchete nao foi fechado corretamente");
                    return 0;
                }
                if(elem->info == '{'){
                    printf("Alguma chave nao foi fechado corretamente");
                    return 0;
                }
            }else
            {
                printf("Nao foi feita a abertura de um parenteses!");
                return 0;
            }
        }
        if(exp[i] == ']'){
            if(pop(&pe,elem)){
                if(elem->info == '('){
                    printf("Algum parentese nao foi fechado corretamente");
                    return 0;
                }
                if(elem->info == '{'){
                    printf("Algum chave nao foi fechado corretamente");
                    return 0;
                }
            }else
            {
                printf("Nao foi feita a abertura de um calchete!");
                return 0;
            }
        }
        if(exp[i] == '}'){
            if(pop(&pe,elem)){
                if(elem->info == '('){
                    printf("Algum parentese nao foi fechado corretamente");
                    return 0;
                }
                if(elem->info == '['){
                    printf("Algum colchete nao foi fechado corretamente");
                    return 0;
                }
            }else
            {
                printf("Nao foi feita a abertura de uma chave!");
                return 0;
            }

        }
        i++;
    }
    if(pilha_vazia(pe)){
        return 1;
    }else
    {
        return 0;
    }
}

int converte_pos_fixa(char *exp, char *res){
    int i = 0,j = 0;
    Pilha pe;
    pe = cria_pilha();
    Tipo_dado *elem,elem_aux;
    elem = (Tipo_dado*)malloc(sizeof(Tipo_dado));
    while(exp[i] != '\0'){
        if(exp[i] == '+'||exp[i] == '-'||exp[i] == '*'|| exp[i] == '/'|| exp[i] == '^'){
            if(exp[i + 1] == '+'||exp[i + 1] == '-'||exp[i + 1] == '*'|| exp[i + 1] == '/'|| exp[i + 1] == '^'){
                printf("\nFalha na equacao: foram colocados dois operadores em sequencia!");
                return 0;
           }
           if(exp[i] == '+'||exp[i] == '-'){
                le_topo(pe,elem);
                while(!pilha_vazia(pe)&&(elem->info == '+'||elem->info == '-'||elem->info == '*'|| elem->info == '/'|| elem->info == '^')){
                    pop(&pe,elem);
                    res[j] = elem->info;
                    j++;
                    le_topo(pe,elem);
                }
                elem_aux.info = exp[i];
                push(&pe,elem_aux);
           }else if(exp[i] == '*'|| exp[i] == '/'){
                le_topo(pe,elem);
                while(!pilha_vazia(pe)&&(elem->info == '*'|| elem->info == '/'|| elem->info == '^')){
                    pop(&pe,elem);
                    res[j] = elem->info;
                    j++;
                    le_topo(pe,elem);
                }
                elem_aux.info = exp[i];
                push(&pe,elem_aux);
           }else
           {
                le_topo(pe,elem);
                while(!pilha_vazia(pe)&&(elem->info == '^')){
                    pop(&pe,elem);
                    res[j] = elem->info;
                    j++;
                    le_topo(pe,elem);
                }
                elem_aux.info = exp[i];
                push(&pe,elem_aux);
           }
        }

        if(exp[i] >= 'A' && exp[i] <= 'F'){
            if(exp[i + 1] >= 'A' && exp[i + 1] <= 'F'){
                printf("\nFalha na equacao: foram colocados dois operandos em sequencia!");
                return 0;
            }else
            {
                res[j]=exp[i];
                j++;
            }
        }

        if(exp[i] == ')'||exp[i] == ']'||exp[i] == '}'){
            do{
                pop(&pe,elem);
                if(elem->info != '(' && elem->info != '[' && elem->info != '{'){
                    res[j]=elem->info;
                    j++;
                }
            }while(elem->info != '(' && elem->info != '[' && elem->info != '{');
        }
        if(exp[i] == '('||exp[i] == '['||exp[i] == '{'){
            elem_aux.info = exp[i];
            push(&pe,elem_aux);
        }


        i++;
    }
    while(!pilha_vazia(pe)){
            pop(&pe,elem);
            res[j] = elem->info;
            j++;
    }
    res[j]='\0';
    return 1;
}

int avalicao_expressao(char* res, float *valor){
    int i=0,flag[6]={0,0,0,0,0,0};
    Pilha P = cria_pilha();
    Tipo_dado f;
    float x1,x2,literais[6];
   while(res[i] != '\0'){
        if (res[i]>='A'&&res[i]<='F'){
            if (flag[res[i]-'A']==0){
                printf("\nDigite o valor de %c:",res[i]);
                setbuf(stdin,NULL);
                scanf("%f",&(f.num));
                flag[res[i]-'A']= 1;
                literais[res[i]-'A']=f.num;
                push(&P,f);

            }else{
                f.num = literais[res[i]-'A'];
                push(&P,f);
            }
        }
        if (res[i]=='+'||res[i]=='-'||res[i]=='/'||res[i]=='*'||res[i]=='^'){
            pop(&P,&f);
            x1 = f.num;
            pop(&P,&f);
            x2 = f.num;
            if(res[i]=='+')
                x1=x1+x2;
            if(res[i]=='-')
                x1=x2-x1;
            if(res[i]=='*')
                x1=x1*x2;
            if(res[i]=='/')
                x1=x2/x1;
            if(res[i]=='^')
                x1=pow(x2,x1);
            f.num = x1;
            push(&P,f);
        }
        i++;
    }
    pop(&P,&f);
    *valor = f.num;

    return 1;
}

int main(){
    char eqc[MAX],res[MAX];
    float valor;
    do{
        res[0]='\0';
        printf("Digite a equacao (Digite FIM para encerrar): ");
        setbuf(stdin,NULL);
        scanf("%[^\n]",eqc);
        if (strcmp(eqc,"FIM")==0){
            break;
        }

        if(validacao_escopo(eqc)){
            printf("\nExito na validacao");
            if(converte_pos_fixa(eqc,res)){
                printf("\nExito na convercao");
                printf("\nEquacao pos-fixa: ");
                printf("%s",res);

                avalicao_expressao(res,&valor);
                printf("O valor da expressao eh: %.2f\n",valor);
            }else
            {
                printf("\nFalha na convercao");
            }
        }else
        {
            printf("\nFalha na validacao");
        }
    }while(1);
    return 0;
}
