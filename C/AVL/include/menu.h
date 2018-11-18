#ifndef MENU_H
#define MENU_H

   /**
    * Imprime o menu e espera o usuario selecionar uma opcao valida do menu.
    *
    * @param options_text: texto de opcoes do menu
    * @param options_number: quantidade de opcoes do menu
    * @return option_selected: opcao selecionada do menu
    */
    short menu(const char *options_text, const short options_number);

#endif /* MENU_H */