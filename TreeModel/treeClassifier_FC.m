function label = treeClassifier(inputFeatures)
% Funzione generata automaticamente da generateTreeCode
% inputFeatures: vettore di feature di input
% label: classe predetta

if inputFeatures(24) < 1.894085
    if inputFeatures(19) < -0.926407
        if inputFeatures(8) < -0.066185
            if inputFeatures(15) < -0.482970
                label = 52;
            else
                label = 48;
            end
        else
            label = 48;
        end
    else
        if inputFeatures(8) < 0.003763
            if inputFeatures(8) < -0.186753
                if inputFeatures(11) < 0.055735
                    if inputFeatures(24) < 0.126809
                        if inputFeatures(9) < 0.195835
                            label = 48;
                        else
                            label = 50;
                        end
                    else
                        label = 48;
                    end
                else
                    if inputFeatures(9) < 0.356904
                        label = 48;
                    else
                        label = 50;
                    end
                end
            else
                if inputFeatures(7) < 0.027177
                    if inputFeatures(10) < 0.130393
                        if inputFeatures(11) < 0.003027
                            label = 48;
                        else
                            if inputFeatures(1) < 1.018185
                                label = 49;
                            else
                                label = 48;
                            end
                        end
                    else
                        label = 48;
                    end
                else
                    if inputFeatures(24) < 0.003724
                        if inputFeatures(13) < 1.138235
                            label = 48;
                        else
                            label = 50;
                        end
                    else
                        if inputFeatures(8) < -0.119822
                            label = 48;
                        else
                            label = 49;
                        end
                    end
                end
            end
        else
            label = 49;
        end
    end
else
    label = 51;
end

end
