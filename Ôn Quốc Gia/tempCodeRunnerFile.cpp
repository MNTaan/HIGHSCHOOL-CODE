if (d != 0)
    {
        cout << 1 << endl;
        cout << fixed << setprecision(2) << dx / d;
        cout << " ";
        cout << fixed << setprecision(2) << dy / d;
    }
    else
    {
        if (d == 0 && (dx != 0 || dy != 0))
            cout << 2;
        else
            cout << 3;
    }