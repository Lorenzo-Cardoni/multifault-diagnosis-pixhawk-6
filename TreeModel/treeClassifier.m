function label = treeClassifier(inputFeatures)
% Funzione generata automaticamente da generateTreeCode
% inputFeatures: vettore di feature di input
% label: classe predetta

if inputFeatures(15) < -1.115931
    if inputFeatures(16) < 1.786899
        label = 0;
    else
        label = 4;
    end
else
    if inputFeatures(4) < 47.591815
        if inputFeatures(8) < 0.008461
            if inputFeatures(8) < -0.185740
                if inputFeatures(5) < 1.000336
                    if inputFeatures(23) < 0.002699
                        label = 0;
                    else
                        label = 2;
                    end
                else
                    if inputFeatures(8) < -0.206555
                        label = 2;
                    else
                        label = 0;
                    end
                end
            else
                if inputFeatures(7) < 0.026579
                    if inputFeatures(8) < -0.135154
                        if inputFeatures(4) < 46.978605
                            label = 0;
                        else
                            label = 3;
                        end
                    else
                        if inputFeatures(9) < 0.010693
                            label = 0;
                        else
                            if inputFeatures(14) < 1.150149
                                label = 0;
                            else
                                label = 1;
                            end
                        end
                    end
                else
                    if inputFeatures(5) < 1.000099
                        label = 2;
                    else
                        if inputFeatures(4) < 42.123060
                            label = 2;
                        else
                            if inputFeatures(22) < 37.058802
                                label = 0;
                            else
                                label = 1;
                            end
                        end
                    end
                end
            end
        else
            label = 1;
        end
    else
        if inputFeatures(1) < 1.075122
            label = 0;
        else
            label = 3;
        end
    end
end

end
