% CreateSignals( {
%   'name', 'DataType', InitialValue, [ min, max ], 'DocUnits', 'description' ;
% } )
function CreateSignals( SigList )

    m = size(SigList,1);

    for i = 1:m
        temp_var = Simulink.Signal;
        % temp_var = nami.Signal;
        temp_var.DataType = SigList{i,2};
        if ischar( SigList{i,3} )
            temp_var.InitialValue = SigList{i,3};
        else
            temp_var.InitialValue = val2str(SigList{i,3});
        end
        if(size(SigList{i,4},2)==2)
            temp_var.Min = SigList{i,4}(1);
            temp_var.Max = SigList{i,4}(2);
        else
            temp_var.Min = [];
            temp_var.Max = [];
        end    

        temp_var.DocUnits = SigList{i,5};
        if ischar(SigList{i,6})
            temp_var.Description = SigList{i,6};
        else
            if size(SigList{i,6},2) > 0
                temp_var.Description = SigList{i,6}{1};
            else
                temp_var.Description = '';
            end
        end

        temp_var.CoderInfo.StorageClass = 'ImportedExtern';
        % if (strcmp(temp_var.DataType,'boolean') == 1)
        %     temp_var.CoderInfo.StorageClass = 'ImportedExtern';
        % else
        %     temp_var.CoderInfo.StorageClass = 'Custom';
        % end

        temp_var.CoderInfo.Alias = '';
        %temp_var.CoderInfo.Alignment = -1;
        % if (strcmp(temp_var.DataType,'boolean') == 1)
        %     temp_var.CoderInfo.CustomStorageClass = 'Default';
        % else
        %     temp_var.CoderInfo.CustomStorageClass = 'ImportedExternFar';
        % end

        if isempty( SigList{i,3} )
            temp_var.Dimensions = 1;
        else
            if(size(SigList{i,3},1)==1)
               temp_var.Dimensions = size(SigList{i,3},2);
            else
               temp_var.Dimensions = size(SigList{i,3}); 
            end
        end
        temp_var.DimensionsMode = 'Fixed';

        %temp_var.DimensionsMode = 'auto';
        temp_var.Complexity = 'real';
        temp_var.SamplingMode = 'sample based';  %todo: find why sample based
        temp_var.SampleTime = -1;  

        assignin('base',SigList{i,1},temp_var);
        clear temp_var;
    end
end
