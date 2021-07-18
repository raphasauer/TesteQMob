# Teste de desenvolvimento para vaga C++/Qt na Qmob
Teste de desenvolvimento para vaga C++/Qt na empresa Qmob, por Raphael Sauer. Ambas atividades foram desenvolvidas utilizando Ubuntu 20.04, e compiladas utilizando o CMake > 3.6.

## Tarefa 1
Foi desenvolvido um método que constroi um formulário para editar um objeto do tipo `Q_GADGET`, desde que tal objeto esteja resgistrado no sistema de meta objetos fornecidos pelo Qt. A entrada para o código consiste em um ponteiro e o nome da classe do `Q_GAGDET`. O ponteiro é utilizado para que os valores descritos no formulário possam ser armazenados depois que o formulário é fechado. O nome da classe é utilizado para que se possa acessar as informações do objeto a partir do sistema meta objetos.

O formulário é construído pela iteração nas propriedades do meta objeto. Para cada propriedade, são adicionadas uma `QLabel` com o nome e um editor de valores conforme definidos no .pdf:

- `enum` são definidos por um `QComboBox` que contém os nomes definidos no `enum`
- `float` são definidos por uma `QDoubleSpinBox`
- `quint16` e `quint8` são definidos por uma `QSpinBox`
- `bool` são definidos por uma `QCheckBox`
- `struct` são definidos por um `QFrame` que contém os tipos da `struct` para serem editados. Só é possível se a `struct` também estiver registrada no sistema de meta objetos.
- Ponteiros são editados reproduzindo seu conteúdo _n_ vezes, de forma similar à `struct` 

O resultado final pode ser visto na imagem a seguir:

![image](https://user-images.githubusercontent.com/24641708/126082442-829b7714-5edf-4de1-aa1d-e635330dfab0.png)

As alterações feitas no objeto são armazenadas no ponteiro enviado. Não consegui, porém, armazenar alterações que ocorrem em algum `Q_GAGDET` interno ao `Q_GADGET`principal. Fiz pesquisas intensivas mas ainda não encontrei uma forma de acessar o ponteiro para um `Q_GADGET` mais interno, para que seja possível gravar os valores e alocar memória para seus parâmetros. 

## Tarefa 2
Foi desenvolvida um método que adiciona objetos do tipo `Player` a uma tabela feita em QML. O script recebe uma `QVariantList`, onde elementos do tipo `Player` estão armazenados. Quando o componente está sendo carregado, essa lista é iterada de forma a adicionar as propriedades dos `Players` na tabela. O script adiciona primeiro uma `ScrollView`, para que a tabela seja rolável. Dentro dessa `ScrollView` foi adicionada uma `TableView`. Na `TableView`, a`TableModel` foi definida com `TableModelColumn` correspondentes as propriedades do `Player`.

O resultado final pode ser visto na imagem a seguir:

![image](https://user-images.githubusercontent.com/24641708/126082625-061158e3-2ff3-41d3-973e-9e7aa97f978c.png)

Meu objetivo era fazer as propriedades de forma dinâmica, porém não encotrei como acessar as informações das propriedades de um `QVariant` dentro do QML. Caso tivesse acesso a essas propriedades, poderia montar a tabela com o cabeçalho customizado. 

## Considerações finais
Agradeço a Qmob pela entrevista e pela oportunidade de concorrer a vaga. Também agradeço ao Sandro, que tirou algumas dúvidas que eu tinha a respeito da atividade. 
