struct Processo {
    int _id;
    int _prioridade;
    std::string _nome;
    Processo* next;
    Processo* previous;

    int getID();
    int getPrioridade();
    std::string getNome();

    Processo() = default;
    Processo(int id, std::string nome, int prioridade);
    double tempo_reservado_processo();
    void imprimir_dados();
};