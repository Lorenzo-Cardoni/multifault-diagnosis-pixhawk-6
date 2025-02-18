function generateTreeCode(model, outputFileName)
    % generateTreeCode - Converte un modello Classification Tree in codice MATLAB con if/else
    %
    % model: un oggetto CompactClassificationTree (addestrato con fitctree o simili)
    % outputFileName: nome del file in cui salvare il codice generato (es. 'treeCode.m')
    %
    % Il file generato conterrà una funzione MATLAB che implementa il modello decisionale.
    
    % Apri il file in cui salvare il codice
    fid = fopen(outputFileName, 'w');
    
    % Scrivi l'intestazione della funzione
    fprintf(fid, 'function label = treeClassifier(inputFeatures)\n');
    fprintf(fid, '%% Funzione generata automaticamente da generateTreeCode\n');
    fprintf(fid, '%% inputFeatures: vettore di feature di input\n');
    fprintf(fid, '%% label: classe predetta\n\n');
    
    % Scrivi il codice del tree
    writeNode(model, 1, fid, 0);
    
    % Scrivi la chiusura della funzione
    fprintf(fid, '\nend\n');
    
    % Chiudi il file
    fclose(fid);
    
    disp(['Codice generato e salvato in: ', outputFileName]);
end

function writeNode(tree, nodeIndex, fid, indentLevel)
    % Funzione ricorsiva per scrivere i nodi dell'albero
    
    % Aggiungi indentazione per migliorare la leggibilità
    indent = repmat('    ', 1, indentLevel);
    
    % Controlla se il nodo è terminale
    if isLeaf(tree, nodeIndex)
        % Nodo terminale: restituisci la classe
        className = tree.NodeClass{nodeIndex};
        fprintf(fid, '%slabel = %d;\n', indent, className);
    else
        % Nodo non terminale: aggiungi condizione if
        predictorIndex = tree.CutPredictorIndex(nodeIndex); % Indice del predittore
        threshold = tree.CutPoint(nodeIndex);               % Soglia di split
        
        % Scrivi la condizione
        fprintf(fid, '%sif inputFeatures(%d) < %.6f\n', indent, predictorIndex, threshold);
        
        % Scrivi il ramo sinistro
        writeNode(tree, tree.Children(nodeIndex, 1), fid, indentLevel + 1);
        
        % Scrivi il ramo destro
        fprintf(fid, '%selse\n', indent);
        writeNode(tree, tree.Children(nodeIndex, 2), fid, indentLevel + 1);
        
        % Fine del blocco if
        fprintf(fid, '%send\n', indent);
    end
end

function isLeafNode = isLeaf(tree, nodeIndex)
    % Verifica se un nodo è terminale (foglia)
    isLeafNode = tree.Children(nodeIndex, 1) == 0 && tree.Children(nodeIndex, 2) == 0;
end
