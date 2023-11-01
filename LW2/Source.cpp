#include "AudioItems.h"

namespace AudioItems {

    ItemOfAudio::ItemOfAudio(const std::string& title, int duration) : title(title), duration(duration) {}

    void ItemOfAudio::Play() {
        std::cout << "Воспроизведение: " << title << " (" << duration << " секунд)" << std::endl;
    }

    std::string ItemOfAudio::GetInfo() const {
        return "Название " + title + ", Время проигрывания: " + std::to_string(duration) + " секунд";
    }

    Song::Song(const std::string& title, int duration, const std::string& singer) : ItemOfAudio(title, duration), singer(singer) {}

    void Song::AddSoundLevel(int level) {
        soundLevels.push_back(level);

    }

    void Song::ChangeVolume() {
        if (soundLevels.empty()) {
            std::cout << "Нет данных о уровнях громкости для песни: " << title << std::endl;
        }
        else {
            int sum = 0;
            for (int level : soundLevels) {
                sum += level;
            }
            int average = sum / soundLevels.size();
            std::cout << "Изменение громкости для песни: " << title << std::endl;
            std::cout << "Средний уровень громкости: " << average << std::endl;
        }
        std::cout << "Изменение громкости для песни: " << title << std::endl;
    }

    void Song::AddToPlaylist(const std::string& songTitle) {
        playlist.push_back(songTitle);
    }

    void Song::CreatePlaylist() {
        if (playlist.empty()) {
            std::cout << "Плейлист пуст для песни: " << title << std::endl;
        }
        else {
            std::cout << "Составление плейлиста для песни: " << title << std::endl;
            std::cout << "Плейлист содержит следующие песни:" << std::endl;
            for (const std::string& song : playlist) {
                std::cout << song << std::endl;
            }
        }
    }

    void Song::Play() {
        std::cout << "Проигрывание песни(трека): " << title << " исполнителя: " << singer << " (" << duration << " секунд)" << std::endl;
    }

    std::string Song::GetInfo() const {
        return "Песня - " + ItemOfAudio::GetInfo() + " , Исполнитель: " + singer;
    }


    Podcast::Podcast(const std::string& title, int duration, const std::string& host) : ItemOfAudio(title, duration), host(host) {}

    void Podcast::AdjustPlaybackSpeed(double speed) {
        playbackSpeed = speed;
        std::cout << "Изменение скорости воспроизведения для подкаста: " << title << std::endl;
        std::cout << "Новая скорость воспроизведения: " << playbackSpeed << std::endl;
    }

    void Podcast::SetPlaybackError(bool error) {
        playbackError = error;
    }

    void Podcast::DownloadEpisode() {
        std::cout << "Загрузка эпизода подкаста: " << title << std::endl;

        if (playbackError) {
            std::cout << "Ошибка во время воспроизведения эпизода: " << title << std::endl;
        }
        else {
            std::cout << "Эпизод загружен успешно." << std::endl;
        }
    }

    void Podcast::Play() {
        std::cout << "Играющийся подкаст: " << title << " Выпущенный от: " << host << " (" << duration << " секунд)" << std::endl;
    }

    std::string Podcast::GetInfo() const {
        return "Подкаст - " + ItemOfAudio::GetInfo() + " , Автор: " + host;

    }

    AudioBook::AudioBook(const std::string& title, int duration, const std::string& author) : ItemOfAudio(title, duration), author(author), narrator("") {}

    void AudioBook::ChangeNarrator(const std::string& newNarrator) {
        narrator = newNarrator;
        std::cout << "Сменить нарратора для аудиокниги " << title << " на " << narrator << std::endl;
    }

    void AudioBook::AddToLibrary() {
        library.push_back(title);
        int position = library.size();  
        std::cout << "Добавление аудиокниги в библиотеку: " << title << " (Позиция: " << position << ")" << std::endl;
    }

    void AudioBook::Play() {
        std::cout << "Проигрываемая аудиокнига: " << title << " Автор: " << author << " Нарратор: " << narrator << " (" << duration << " секунд)" << std::endl;
    }

    std::string AudioBook::GetInfo() const {
        return "Аудиокнига - " + ItemOfAudio::GetInfo() + " , Автор: " + author + " , Нарратор: " + narrator;
    }

    Radio::Radio(const std::string& title, int duration, const std::string& station) : ItemOfAudio(title, duration), station(station), selectedEqualizer(""), isRecording(false) {}

    void Radio::AdjustEQ(const std::string& equalizer) {
        selectedEqualizer = equalizer;
        std::cout << "Настроить эквалайзер для радиостанции: " << station << std::endl;
        std::cout << "Выбран эквалайзер: " << selectedEqualizer << std::endl;
    }

    void Radio::Record() {
        if (isRecording) {
            std::cout << "Завершить запись радиопередачи: " << title << std::endl;
            isRecording = false;
        }
        else {
            std::cout << "Начать запись радиопередачи: " << title << std::endl;
            isRecording = true;
        }
    }

    void Radio::Play() {
        std::string recordingStatus = isRecording ? "Запись активна" : "Запись не активна";
        std::cout << "Играющаяся радиопередача: " << title << " Станция: " << station << " (" << duration << " секунд)" << std::endl;
        std::cout << "Статус записи: " << recordingStatus << std::endl;
    }

    std::string Radio::GetInfo() const {
        std::string recordingStatus = isRecording ? "Запись активна" : "Запись не активна";
        return "Радиопередача - " + ItemOfAudio::GetInfo() + " , Станция: " + station + " , Выбранный эквалайзер: " + selectedEqualizer + " , " + recordingStatus;
    }

    SoundEffect::SoundEffect(const std::string& title, int duration) : ItemOfAudio(title, duration) {}

    void SoundEffect::AdjustPitch() {
        std::cout << "Настроить высоту тона для звукового эффекта: " << title << std::endl;
    }

    void SoundEffect::LoopEffect() {
        std::cout << "Зациклить звуковой эффект: " << title << std::endl;
    }

    void SoundEffect::Play() {
        std::cout << "Проигрываемый звуковой эффект: " << title << " (" << duration << " секунд)" << std::endl;
    }

    std::string SoundEffect::GetInfo() const {
        return "Звуковой эффект - " + ItemOfAudio::GetInfo();
    }

    Interview::Interview(const std::string& title, int duration, const std::string& interviewer)
        : ItemOfAudio(title, duration), interviewer(interviewer), shouldAskQuestions(true), sendText(false), sendAudio(false) {}

    void Interview::SetSendText(bool send) {
        sendText = send;
    }

    void Interview::SetSendAudio(bool send) {
        sendAudio = send;
    }

    void Interview::ShareInterview() {
        std::cout << "Поделиться интервью: " << title << std::endl;
        if (sendText) {
            std::cout << "Отправить текстом" << std::endl;
        }
        if (sendAudio) {
            std::cout << "Отправить аудиозаписью" << std::endl;
        }
    }

    void Interview::Play() {
        std::string questionsStatus = shouldAskQuestions ? "Задавать вопросы" : "Пропуск вопросов";
        std::cout << "Играющееся интервью: " << title << " Интервьюер: " << interviewer << " (" << duration << " секунд)" << std::endl;
        std::cout << "Статус задавания вопросов: " << questionsStatus << std::endl;
    }

    std::string Interview::GetInfo() const {
        std::string questionsStatus = shouldAskQuestions ? "Задавать вопросы" : "Пропуск вопросов";
        return "Интервью - " + ItemOfAudio::GetInfo() + " , Интервьюер: " + interviewer + " , Способы отправки: " + (sendText ? "Текст" : "") + (sendAudio ? "Аудиозапись" : "");
    }


    LiveMusic::LiveMusic(const std::string& title, int duration, const std::string& venue)
        : ItemOfAudio(title, duration), venue(venue) {}

    void LiveMusic::AddTicketPrice(double price) {
        ticketPrices.push_back(price);
    }

    double LiveMusic::FindMinTicketPrice() {
        if (ticketPrices.empty()) {
            return 0;
        }
        return *std::min_element(ticketPrices.begin(), ticketPrices.end());
    }

    double LiveMusic::FindMaxTicketPrice() {
        if (ticketPrices.empty()) {
            return 0;
        }
        return *std::max_element(ticketPrices.begin(), ticketPrices.end());
    }

    void LiveMusic::BuyTickets() {
        double minPrice = FindMinTicketPrice();
        double maxPrice = FindMaxTicketPrice();

        std::cout << "Покупка билетов на концерт " << title << " в " << venue << std::endl;
        std::cout << "Минимальная цена билета: " << minPrice << std::endl;
        std::cout << "Максимальная цена билета: " << maxPrice << std::endl;
    }

    void LiveMusic::Play() {
        std::cout << "Играющийся концерт: " << title << " Место: " << venue << " (" << duration << " секунд)" << std::endl;
    }

    int main() {

        return 0;
    }
}