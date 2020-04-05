#include "file_to_vector.h"

namespace ba = boost::locale::boundary;



std::vector<std::string> extract_words(std::string &file_in) {
    boost::locale::generator gen;
    std::locale loc = gen("");
    std::locale::global(loc);

    std::string text;
    std::vector<std::string> words;
    file_in = "../" + file_in.substr(1,file_in.length()-2);
    if (file_in.substr(file_in.length() - 4, 4) == ".txt"){
        text = read_txt(file_in);}
    else {
        text = read_archive(file_in);
    }

    text = boost::locale::to_lower(boost::locale::fold_case(boost::locale::normalize(text)));

    ba::ssegment_index map(ba::word, text.begin(),text.end());
    map.rule(ba::word_letters);
    for(ba::ssegment_index::iterator it=map.begin(),e=map.end();it!=e;++it)
        words.emplace_back(std::move(*it));
    return words;
}

std::string read_txt (std::string &file_in) {
    std::ifstream ifs(file_in);
    if (ifs.is_open()){
        std::string content( (std::istreambuf_iterator<char>(ifs) ),
                             (std::istreambuf_iterator<char>()    ) );
        return content;}
    else{
        file_in = "../" + file_in;
        read_txt(file_in);
    }
}

std::string read_archive (std::string &file_in) {
    std::vector<std::string> words;
    std::ifstream raw_file(file_in, std::ios::binary);
    std::ostringstream buffer_ss;
    buffer_ss << raw_file.rdbuf();
    std::string buffer{buffer_ss.str()};
    return archive_to_memory(buffer);
}

std::string archive_to_memory(std::string &buffer) {
    struct archive *a;
    struct archive_entry *entry;
    int r;
    off_t filesize;
    std::vector<std::string> result;

    a = archive_read_new();
    archive_read_support_format_all(a);
    archive_read_support_filter_all(a);

    r = archive_read_open_memory(a, buffer.c_str(), buffer.size());
    if (r != ARCHIVE_OK)
        exit(1);
    r = archive_read_next_header(a, &entry);
    if (r != ARCHIVE_OK)
        exit(1);

    filesize = archive_entry_size(entry);
    std::string output(filesize, char{});
    r = archive_read_data(a, &output[0], output.size());
    result.emplace_back(std::move(output));

    archive_read_close(a);
    archive_read_free(a);
    return result[0];
}

