void bacaFile() {
    ifstream file("absensi.txt");
    n = 0;
    if (!file) {
        return;
    }
    string line;
    while (getline(file, line)) {
        int pos = line.find('|');
        if (pos != string::npos) {
            nama[n] = line.substr(0, pos);
            string right = line.substr(pos + 1);
            char st = 'T';
            for (size_t k = 0; k < right.size(); k++) {
                if (right[k] != ' ' && right[k] != '\t') {
                    st = right[k];
                    break;
                }
            }
            if (st == 'h') st = 'H';
            if (st == 't') st = 'T';
            statusArr[n] = st;
            n++;
            if (n >= MAX) break;
        }
    }
    file.close();
}

void urutkanNama() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nama[i] > nama[j]) {
                string tmpN = nama[i];
                nama[i] = nama[j];
                nama[j] = tmpN;
                char tmpS = statusArr[i];
                statusArr[i] = statusArr[j];
                statusArr[j] = tmpS;
            }
        }
    }
}